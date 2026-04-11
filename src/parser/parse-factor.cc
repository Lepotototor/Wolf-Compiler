#include "parser.hh"

#include "../ast_nodes/decrement.hh"
#include "../ast_nodes/increment.hh"
#include "../ast_nodes/number-exp.hh"
#include "../ast_nodes/unary-exp.hh"
#include "../ast_nodes/var.hh"

namespace parser
{

  static bool is_unary(const std::string& repr)
  {
    static std::string unary_tok[] = {
      "+",
      "-",
      "~",
      "!",
    };
    for (const std::string& s : unary_tok)
      if (s == repr)
        return true;
    return false;
  }

  static ast::unary_type get_unary_type(const std::string& c)
  {
    if (c == "+")
      return ast::unary_type::PLUS_U;
    if (c == "-")
      return ast::unary_type::MINUS_U;
    if (c == "~")
      return ast::unary_type::TILDE_U;
    else
      return ast::unary_type::NEGATE_U;
  }

  ast::Exp* Parser::parse_factor()
  {
    ENTER_PARSE_FUNC

    lexer::Token tok = peek_tok();
    std::string repr = lexer::tok_repr(tok);

    if (tok.type() == lexer::NUM_TOK)
      {
        pop_tok();
        return new ast::NumberExp(tok.location_get(), tok.val_get());
      }

    else if (tok == "(")
      {
        pop_tok();
        ast::Exp* exp = parse_exp();
        expect_tok(")");

        return exp;
      }

    else if (is_unary(repr))
      {
        lexer::Token tok = pop_tok();
        ast::Exp* exp = parse_factor();

        misc::Location loc = tok.location_get() + exp->location_get();
        return new ast::UnaryExp(loc, get_unary_type(repr), exp);
      }

    else if (tok.type() == lexer::IDENTIFIER_TOK)
      {
        pop_tok();
        ast::Var* var = new ast::Var(tok.location_get(), tok.val_get());

        tok = peek_tok();
        if (tok == "++")
          {
            pop_tok();
            misc::Location loc = tok.location_get() + var->location_get();
            return new ast::IncrementExp(loc, var, false);
          }
        else if (tok == "--")
          {
            pop_tok();
            misc::Location loc = tok.location_get() + var->location_get();
            return new ast::DecrementExp(loc, var, false);
          }

        return var;
      }

    else if (tok == "++")
      {
        pop_tok();
        // TODO check that exp is a var
        ast::Exp* exp = parse_factor();
        misc::Location loc = tok.location_get() + exp->location_get();
        return new ast::IncrementExp(loc, exp, true);
      }
    else if (tok == "--")
      {
        pop_tok();
        // TODO check that exp is a var
        ast::Exp* exp = parse_factor();
        misc::Location loc = tok.location_get() + exp->location_get();
        return new ast::DecrementExp(loc, exp, true);
      }

    else
      {
        std::clog << "Parse Factor unknow exp\n";
        return nullptr;
      }
  }

}; // namespace parser
