#include "lexer.hh"

#include <fstream>
#include <iostream>

namespace lexer
{
  std::queue<Token> lex(const std::string& file, driver::WolfDriver& wd)
  {
    std::ifstream in{file};
    lexer::Lexer lexer{in};
    lexer.set_debug(wd.lex_trace);

    std::queue<Token> res;
    lexer.lex(wd, res);

    return res;
  }
} // namespace lexer
