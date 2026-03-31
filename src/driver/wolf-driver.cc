#include "wolf_driver.hh"
#include "../misc/debug.hh"
#include "../misc/format_helper.hh"

#include <cstdlib>
#include <iostream>

using namespace misc;
namespace driver
{

  const char* program_name = "Wolf";

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
          }
        else if (arg == "--parse")
          {
            code_gen = false;
          }
        else if (arg == "--codegen")
          {
            code_emit = false;
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
  }

  void WolfDriver::run()
  {
    for (const std::string& file : input_files_)
      {
        int dot = file.find(".");
        std::string filename = file.substr(0, dot);
        std::string ext = file.substr(dot);

        std::cout << "File: " << filename << " has extension " << ext << "\n";
        if (ext == ".c")
          {
            std::string cmd = "cpp -P " + file + " -o " + filename + ".i";
            std::cout << cmd << "\n";
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
            // do your stuff with compiler
          }

        if (!assembl)
          continue;

        if (ext == ".c" || ext == ".i" || ext == ".s" || ext == ".S")
          {
            std::string cmd = "as " + (ext == ".S" ? file : filename + ".s")
              + " -o " + filename + ".o";
            std::cout << cmd << "\n";
            int r = system(cmd.c_str());
            if (r != 0)
              {
                exit(1);
              }
          }
      }

    if (compile && assembl && link)
      {
        std::string cmd = "ld";
        for (const std::string& file : input_files_)
          {
            std::string filename = file.substr(0, file.find("."));
            cmd += " " + filename + ".o";
          }
        cmd += " -o " + output_name;

        std::cout << cmd << "\n";
        int r = system(cmd.c_str());
        if (r != 0)
          {
            exit(1);
          }
      }
  }
} // namespace driver
