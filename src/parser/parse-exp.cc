#include "parser.hh"

#include "../ast_nodes/binary-exp.hh"

namespace parser
{

  bool is_binary(const lexer::Token& tok)
  {
    char c = tok_repr(tok)[0];

    static const char unary_tok[] = {'+', '-', '*', '/', '%', 0};
    for (const char* s = unary_tok; *s; s++)
      if (*s == c)
        return true;
    return false;
  }

  static ast::binary_type get_binary_type(char c)
  {
    if (c == '+')
      return ast::binary_type::ADD;
    else if (c == '-')
      return ast::binary_type::SUB;
    else if (c == '*')
      return ast::binary_type::MULT;
    else if (c == '/')
      return ast::binary_type::DIV;
    else
      return ast::binary_type::MOD;
  }

  ast::Exp* Parser::parse_exp(unsigned min_pred)
  {
    ENTER_PARSE_FUNC

    ast::Exp* left = parse_factor();

    lexer::Token tok = peek_tok();

    while (is_binary(tok) && precedence(tok) >= min_pred)
      {
        pop_tok();

        ast::Exp* right = parse_exp(precedence(tok) + 1);
        if (right == nullptr)
          {
            std::clog << "No right member for binop\n";
          }

        misc::Location loc = left->location_get() + right->location_get();
        ast::binary_type type = get_binary_type(lexer::tok_repr(tok)[0]);

        left = new ast::BinaryExp(loc, type, left, right);

        tok = peek_tok();
      }

    return left;
  }

}; // namespace parser
