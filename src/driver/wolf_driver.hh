#pragma once

#include <string>
#include <vector>

namespace driver
{
  class WolfDriver
  {
  public:
    WolfDriver(int argc, char** argv);

    std::string program_name;

    bool save_temps = false;

    bool lex_trace = false;
    bool parse_trace = false;

    bool parse = true;
    bool code_gen = true;
    bool code_emit = true;

    bool compile = true;
    bool assembl = true;
    bool link = true;

    void run();

  private:
    void parse_arg(int argc, char** argv);

    std::vector<std::string> input_files_;
  };
} // namespace driver
