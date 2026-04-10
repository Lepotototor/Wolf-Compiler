#include "parser.hh"

#include "../ast_nodes/block.hh"
#include "../ast_nodes/if.hh"
#include "../ast_nodes/null.hh"
#include "../ast_nodes/return.hh"
#include "../ast_nodes/stmt-exp.hh"

using namespace lexer;

namespace parser
{
  ast::Statement* Parser::parse_statement()
  {
    ENTER_PARSE_FUNC

    const lexer::Token& tok = peek_tok();

    if (tok == ";")
      {
        pop_tok();
        return new ast::Null(tok.location_get());
      }
    else if (tok == "{")
      {
        return parse_block_statement();
      }
    else if (tok == "return")
      {
        return parse_return_statement();
      }
    else if (tok == "if")
      {
        return parse_if_statement();
      }
    else
      {
        ast::ExpressionStatement* exp_stmt =
          new ast::ExpressionStatement{parse_exp()};
        expect_tok(";");
        return exp_stmt;
      }
  }

  ast::Statement* Parser::parse_if_statement()
  {
    ENTER_PARSE_FUNC

    expect_tok("if");
    expect_tok("(");

    ast::Exp* cond = parse_exp();

    expect_tok(")");

    ast::Statement* then = parse_statement();
    ast::Statement* els = nullptr;

    const lexer::Token& tok = peek_tok();

    if (tok == "else")
      {
        pop_tok();

        els = parse_statement();
      }

    misc::Location loc =
      cond->location_get() + (els ? els->location_get() : then->location_get());

    return new ast::IfStatement(loc, cond, then, els);
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
