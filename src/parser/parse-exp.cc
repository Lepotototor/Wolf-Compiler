#include "parser.hh"

#include "../ast_nodes/number-exp.hh"
#include "../ast_nodes/unary-exp.hh"

namespace parser
{

  static bool is_unary(char c)
  {
    static const char unary_tok[] = {'+', '-', '~', '!', 0};
    for (const char* s = unary_tok; *s; s++)
      if (*s == c)
        return true;
    return false;
  }

  ast::unary_type get_unary_type(char c)
  {
    if (c == '+')
      return ast::unary_type::PLUS_U;
    if (c == '-')
      return ast::unary_type::MINUS_U;
    if (c == '~')
      return ast::unary_type::TILDE_U;
    else
      return ast::unary_type::NEGATE_U;
  }

  ast::Exp* Parser::parse_exp()
  {
    const lexer::Token tok = peek_tok();
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

    else if (is_unary(repr[0]))
      {
        lexer::Token tok = pop_tok();
        ast::Exp* exp = parse_exp();

        misc::Location loc = tok.location_get() + exp->location_get();
        return new ast::UnaryExp(loc, get_unary_type(repr[0]), exp);
      }

    else
      {
        std::clog << "Parse EXP unknow exp";
        return nullptr;
      }
  }

}; // namespace parser
