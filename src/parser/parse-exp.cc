#include "parser.hh"

#include "../ast_nodes/binary-exp.hh"

#include "../misc/debug.hh"

namespace parser
{

  bool is_binary(const lexer::Token& tok)
  {
    std::string c = tok_repr(tok);

    static const char* unary_tok[] = {
      "+",  "-",  "*",  "/",  "%", "<<", ">>", "&",  "|", "^",
      "&&", "||", "==", "!=", "<", "<=", ">",  ">=", 0};
    for (const char** s = unary_tok; *s; s++)
      if (*s == c)
        return true;
    return false;
  }

  static ast::binary_type get_binary_type(const std::string& s)
  {
    if (s == "+")
      return ast::binary_type::ADD;
    else if (s == "-")
      return ast::binary_type::SUB;
    else if (s == "*")
      return ast::binary_type::MULT;
    else if (s == "/")
      return ast::binary_type::DIV;
    else if (s == "%")
      return ast::binary_type::MOD;
    else if (s == "<<")
      return ast::binary_type::L_SHIFT;
    else if (s == ">>")
      return ast::binary_type::R_SHIFT;
    else if (s == "&")
      return ast::binary_type::B_AND;
    else if (s == "|")
      return ast::binary_type::B_OR;
    else if (s == "^")
      return ast::binary_type::XOR;
    else if (s == "&&")
      return ast::binary_type::L_AND;
    else if (s == "||")
      return ast::binary_type::L_OR;
    else if (s == "==")
      return ast::binary_type::EQ;
    else if (s == "!=")
      return ast::binary_type::NE;
    else if (s == "<")
      return ast::binary_type::LT;
    else if (s == "<=")
      return ast::binary_type::LE;
    else if (s == ">")
      return ast::binary_type::GT;
    else if (s == ">=")
      return ast::binary_type::GE;
    else
      {
        std::string txt = "No binary type for " + s;
        notimplmented(txt.c_str());
      }
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
        ast::binary_type type = get_binary_type(lexer::tok_repr(tok));

        left = new ast::BinaryExp(loc, type, left, right);

        tok = peek_tok();
      }

    return left;
  }

}; // namespace parser
