#include "wolf_driver.hh"

#include <iostream>

const char* driver::program_name = "Wolf";

void driver::WolfDriver::parse_arg(int argc, char** argv)
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

      else if (arg == "--help")
        {
          std::cout << "help";
          exit(0);
        }

      else
        {
          std::cerr << "Warning: " << "unknow option `" << arg << "`\n";
        }
    }
}
