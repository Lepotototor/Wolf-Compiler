#include "parser.hh"

#include "../ast_nodes/return.hh"

using namespace lexer;

namespace parser
{
  ast::Statement* Parser::parse_statement()
  {
    ENTER_PARSE_FUNC

    return parse_return_statement();
  }

  ast::Statement* Parser::parse_return_statement()
  {
    ENTER_PARSE_FUNC

    const Token& ret_tok = expect_tok("return");

    Token semi_tok = peek_tok();
    ast::Exp* return_exp = nullptr;

    if (semi_tok != ';')
      {
        return_exp = parse_exp();
        semi_tok = expect_tok(";");
      }
    else
      {
        pop_tok();
      }

    return new ast::ReturnExp(ret_tok + semi_tok, return_exp);
  }

} // namespace parser
