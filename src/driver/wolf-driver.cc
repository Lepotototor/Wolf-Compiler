#include "wolf-driver.hh"
#include "../misc/debug.hh"
#include "../misc/format-helper.hh"

#include "../lexer/lexer.hh"
#include "../parser/parser.hh"

#include "../assembly/code-emission.hh"
#include "../ast_nodes/binder.hh"
#include "../ast_nodes/pretty-printer.hh"
#include "../ast_nodes/renamer.hh"
#include "../visitor/assembly-generation.hh"
#include "../visitor/yakir-generation.hh"
#include "../yakir/pretty_printer.hh"

#include "../yakir/program.hh"

#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace misc;
namespace driver
{

  const char* program_name = "Wolf";

  misc::Error& WolfDriver::error_get() { return error_; }

  WolfDriver::WolfDriver(int argc, char** argv) { this->parse_arg(argc, argv); }

  void WolfDriver::parse_arg(int argc, char** argv)
  {
    program_name = argv[0];

    for (int i = 1; i < argc; i++)
      {
        std::string arg = argv[i];

        if (arg[0] != '-')
          {
            input_files_.emplace_back(arg);
          }
        else if (arg == "-save-temps")
          {
            save_temps = true;
          }

        else if (arg == "-lex-trace")
          {
            lex_trace = true;
          }
        else if (arg == "-parse-trace")
          {
            parse_trace = true;
          }
        else if (arg == "--lex")
          {
            parse = false;
            assembl = false;
          }
        else if (arg == "--parse")
          {
            code_gen = false;
            assembl = false;
          }
        else if (arg == "--codegen")
          {
            code_emit = false;
            assembl = false;
          }

        else if (arg == "-E")
          {
            compile = false;
          }
        else if (arg == "-S")
          {
            assembl = false;
          }
        else if (arg == "-c")
          {
            link = false;
          }

        else if (arg == "-o")
          {
            i++;
            if (argv[i] == nullptr)
              {
                notimplmented("Implement err message for non existent file");
              }
            else
              {
                output_name = argv[i];
              }
          }

        else if (arg == "--help")
          {
            notimplmented("Implement help msg for command line");
          }

        else
          {
            error_ << bold(program_name) << ": " << misc::warn()
                   << "unrecognized command-line option `" << bold(arg)
                   << "`\n";
          }
      }

    if (input_files_.size() == 0)
      {
        error_ << misc::error_type::failure << bold(program_name) << ": "
               << misc::err() << "not given input files\n";
        error_.exit();
      }
  }

  void WolfDriver::run()
  {
    for (const std::string& file : input_files_)
      {
        int dot = file.find_last_of(".");
        std::string filename = file.substr(0, dot);
        std::string ext = file.substr(dot);

        // std::cout << "File: " << filename << " has extension " << ext << "\n";
        if (ext == ".c")
          {
            std::string cmd = "cpp " + file + " -o " + filename + ".i";
            // std::cout << cmd << "\n";
            int r = system(cmd.c_str());
            if (r != 0)
              {
                exit(1);
              }
          }

        if (!compile)
          continue;

        if (ext == ".c" || ext == ".i")
          {
            compiler(filename);
          }

        if (!assembl)
          continue;

        if (ext == ".c" || ext == ".i" || ext == ".s" || ext == ".S")
          {
            std::string cmd = "as -g -O0 "
              + (ext == ".S" ? file : filename + ".s") + " -o " + filename
              + ".o";
            int r = system(cmd.c_str());
            if (r != 0)
              {
                exit(1);
              }
          }
      }

    if (compile && assembl && link)
      {
        std::string cmd = "gcc";
        //std::string cmd = "ld";
        for (const std::string& file : input_files_)
          {
            std::string filename = file.substr(0, file.find_last_of("."));
            cmd += " " + filename + ".o";
          }
        cmd += " -o " + output_name;

        // std::cout << cmd << "\n";
        int r = system(cmd.c_str());
        if (r != 0)
          {
            exit(1);
          }
      }

    for (const std::string& file : input_files_)
      {
        std::string cmd = "rm -f " + file + ".i " + file + ".s " + file + ".o ";
        system(cmd.c_str());
      }
  }

  void WolfDriver::compiler(const std::string& file)
  {
    // Lexing doing with re/flex
    std::queue<lexer::Token> tokens = lexer::lex(file + ".i", *this);
    /*
    while (tokens.size() > 0)
      {
        const lexer::Token& tok = tokens.front();
        std::cout << tok << "\n";
        tokens.pop();
      }
      */

    ast::Ast* program = nullptr;
    if (parse)
      {
        parser::Parser parser{*this, tokens};
        parser.parse();
        program = parser.program_get();

        error_.exit_on_error();
      }

    std::cout << "\t___PROGRAM___\n";
    std::cout << *program;

    ast::Binder binder{error_};
    program->accept(binder);

    error_.exit_on_error();

    ast::Renamer renamer;
    program->accept(renamer);

    std::cout << "\n\t___PROGRAM___\n";
    std::cout << *program;

    yakir::YakirNode* yakir_pg = nullptr;

    if (code_gen && program)
      {
        ast::YakirGeneration yakir_gen;
        program->accept(yakir_gen);
        yakir_pg = yakir_gen.res_get();
      }

    if (code_emit && yakir_pg)
      {
        std::cout << "\n\t___YAKIR___\n" << *yakir_pg;

        yakir::AssemblyGeneration asm_gen;
        yakir_pg->accept(asm_gen);

        assembly::AsmNode* asm_pg = asm_gen.res_get();
        std::cout << "\n\t___ASM___\n" << *asm_pg;

        std::ofstream file_out{file + ".s"};
        file_out << *asm_pg;
        file_out.close();

        delete asm_pg;
      }

    delete program;
    delete yakir_pg;
  }
} // namespace driver
