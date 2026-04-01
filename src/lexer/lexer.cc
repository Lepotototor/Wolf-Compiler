#include "lexer.hh"

#include <fstream>
#include <iostream>

namespace lexer
{
  std::vector<Token> lex(const std::string& file, driver::WolfDriver& wd)
  {
    std::ifstream in{file};
    lexer::Lexer lexer{in};
    lexer.set_debug(wd.lex_trace);

    std::vector<Token> res;
    lexer.lex(wd, res);

    return res;
  }
} // namespace lexer
