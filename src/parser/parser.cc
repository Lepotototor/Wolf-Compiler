#include "parser.hh"

#include "../misc/format-helper.hh"

#include <iostream>

namespace parser
{

  const lexer::Token& Parser::peek_tok()
  {
    const lexer::Token& tok = tokens_.front();

    if (wd_.parse_trace)
      {
        std::cout << "Peek token: " << tok << "\n";
      }

    return tok;
  }

  const lexer::Token Parser::pop_tok()
  {
    lexer::Token tok = tokens_.front();
    tokens_.pop();

    if (wd_.parse_trace)
      {
        std::cout << "Pop  token: " << tok << "\n";
      }

    return tok;
  }

  const lexer::Token Parser::expect_tok(const std::string& str)
  {
    const lexer::Token tok = this->pop_tok();

    if (tok != str)
      {
        mismatch_tok(tok, str);
      }

    return tok;
  }

  const lexer::Token Parser::expect_tok(char c)
  {
    const lexer::Token tok = this->pop_tok();

    if (tok != c)
      {
        mismatch_tok(tok, std::string(c, 1));
      }

    return tok;
  }

  void Parser::mismatch_tok(const lexer::Token& tok, const std::string& exp)
  {
    wd_.error_get() << misc::error_type::parse << misc::bold(wd_.program_name)
                    << ": " << misc::err() << "Expected token \""
                    << misc::bold(exp) << "\" but got \""
                    << misc::bold(lexer::tok_repr(tok)) << "\"\n";
  }

  void Parser::unexpected(const lexer::Token& tok)
  {
    wd_.error_get() << misc::error_type::parse << misc::bold(wd_.program_name)
                    << ": " << misc::err() << "Unexpected token \""
                    << misc::bold(tok_repr(tok)) << "\"\n";
  }

} // namespace parser
