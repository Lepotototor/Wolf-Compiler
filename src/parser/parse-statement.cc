#include "parser.hh"

#include "../ast_nodes/exp-list.hh"
#include "../ast_nodes/return-exp.hh"

using namespace lexer;

namespace parser
{
  ast::Exp* Parser::parse_statement()
  {
    std::vector<ast::Exp*> exps;
    exps.emplace_back(parse_return_statement());

    misc::Location loc =
      exps.front()->location_get() + exps.back()->location_get();

    return new ast::ExpList(loc, exps);
  }

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
