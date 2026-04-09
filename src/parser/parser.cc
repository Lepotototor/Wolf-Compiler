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
        mismatch_tok(tok, std::string(1, c));
      }

    return tok;
  }

  void Parser::mismatch_tok(const lexer::Token& tok, const std::string& exp)
  {
    wd_.error_get() << misc::error_type::parse << misc::bold(wd_.program_name)
                    << ": " << misc::err() << "Expected token \""
                    << misc::bold(exp) << "\" but got \""
                    << misc::bold(lexer::tok_repr(tok)) << "\" "
                    << tok.location_get() << "\n";
  }

  void Parser::unexpected(const lexer::Token& tok)
  {
    wd_.error_get() << misc::error_type::parse << misc::bold(wd_.program_name)
                    << ": " << misc::err() << "Unexpected token \""
                    << misc::bold(tok_repr(tok)) << "\"\n";
  }

  unsigned Parser::precedence(const lexer::Token& tok)
  {
    if (tok == "*" || tok == "/" || tok == "%")
      {
        return 420;
      }
    else if (tok == "+" || tok == "-")
      {
        return 69;
      }
    else if (tok == "<<" || tok == ">>")
      {
        return 68;
      }
    else if (tok == "<" || tok == "<=" || tok == ">" || tok == ">=")
      {
        return 67;
      }
    else if (tok == "==" || tok == "!=")
      {
        return 66;
      }
    else if (tok == "&")
      {
        return 65;
      }
    else if (tok == "^")
      {
        return 64;
      }
    else if (tok == "|")
      {
        return 63;
      }
    else if (tok == "&&")
      {
        return 7;
      }
    else if (tok == "||")
      {
        return 6;
      }
    else if (tok == "=")
      {
        return 1;
      }
    else
      {
        std::cerr << misc::warn() << "No precedenece fro token " << tok << "\n";
        return 0;
      }
  }

} // namespace parser
