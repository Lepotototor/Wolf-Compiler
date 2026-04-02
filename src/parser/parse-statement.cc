#include "parser.hh"

#include "../ast_nodes/return-exp.hh"

using namespace lexer;

namespace parser
{
  ast::Exp* Parser::parse_statement() { return parse_return_statement(); }

  ast::Exp* Parser::parse_return_statement()
  {
    const Token& ret_tok = expect_tok("return");

    Token semi_tok = peek_tok();
    ast::Exp* return_exp = nullptr;

    if (semi_tok != ';')
      {
        return_exp = parse_exp();
        semi_tok = expect_tok(";");
      }

    return new ast::ReturnExp(ret_tok + semi_tok, return_exp);
  }

} // namespace parser
