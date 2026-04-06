#include "parser.hh"

#include "../ast_nodes/binary-exp.hh"

namespace parser
{

  bool is_binary(char c)
  {
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

  ast::Exp* Parser::parse_exp()
  {
    ENTER_PARSE_FUNC

    ast::Exp* left = parse_factor();

    lexer::Token tok = peek_tok();

    while (tok == "+" || tok == "-")
      {
        pop_tok();

        ast::Exp* right = parse_factor();
        if (right == nullptr)
          {
            std::clog << "No right member\n";
          }

        misc::Location loc = left->location_get() + right->location_get();
        ast::binary_type type = get_binary_type(lexer::tok_repr(tok)[0]);

        left = new ast::BinaryExp(loc, type, left, right);

        tok = peek_tok();
      }

    return left;
  }

}; // namespace parser
