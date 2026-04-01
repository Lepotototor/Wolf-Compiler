#pragma once

#include <string>
#include <vector>

#include "../misc/error.hh"

namespace driver
{
  class WolfDriver
  {
  public:
    WolfDriver(int argc, char** argv);

    std::string program_name;

    void run();

    misc::Error& error_get();

    bool lex_trace = false;
    bool parse_trace = false;

  private:
    void parse_arg(int argc, char** argv);

    // Do internal compiler steps (lex, parse, bind, ...)
    void compiler(const std::string& file);

    std::vector<std::string> input_files_;

    bool save_temps = false;

    bool parse = true;
    bool code_gen = true;
    bool code_emit = true;

    bool compile = true;
    bool assembl = true;
    bool link = true;

    std::string output_name = "a.out";

    misc::Error error_;
  };
} // namespace driver
