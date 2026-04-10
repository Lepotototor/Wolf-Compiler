#include "parser.hh"

#include "../ast_nodes/assign.hh"
#include "../ast_nodes/binary-exp.hh"
#include "../ast_nodes/conditional.hh"
#include "../ast_nodes/number-exp.hh"
#include "../ast_nodes/pretty-printer.hh"
#include "../ast_nodes/var.hh"

#include "../misc/debug.hh"
#include "../misc/format-helper.hh"

namespace parser
{

  // Implemented at end of file
  static bool is_binary(const lexer::Token& tok);
  static ast::binary_type get_binary_type(const std::string& s);

  ast::Exp* Parser::parse_exp(unsigned min_pred)
  {
    ENTER_PARSE_FUNC

    ast::Exp* left = parse_factor();

    lexer::Token tok = peek_tok();

    while (is_binary(tok) && precedence(tok) >= min_pred)
      {
        pop_tok();

        // Only assignements operathors have precedemce of 1
        if (precedence(tok) == 1)
          {
            // No precedence climbing because '=' is right assoc
            ast::Exp* right = parse_exp(precedence(tok));
            if (right == nullptr)
              {
                std::clog << "No right member for assignment\n";
              }

            ast::Var* lvalue = dynamic_cast<ast::Var*>(left);
            if (lvalue == nullptr)
              {
                wd_.error_get()
                  << misc::error_type::parse << left->location_get()
                  << misc::err()
                  << "Trying to assign a value to a non-variable \n";
              }

            misc::Location loc = left->location_get() + right->location_get();

            // For assignement with binary operation
            if (tok != "=")
              {
                std::string repr = lexer::tok_repr(tok);
                std::cout << "Repr: " << repr;
                repr = repr.substr(0, repr.size() - 1);
                std::cout << "    newRepr: " << repr << "\n";
                ast::binary_type type = get_binary_type(repr);

                right = new ast::BinaryExp(loc, type, left, right);
                lvalue = new ast::Var(lvalue->location_get(),
                                      lvalue->identifier_get());
              }

            left = new ast::AssignExp(loc, lvalue, right);
          }

        else if (tok == "?")
          {
            tok = peek_tok();

            ast::Exp* then = nullptr;
            std::cout << "Peek tok: " << tok << "\n";
            if (tok == ":")
              {
                then = new ast::NumberExp(tok.location_get(), "1");
              }
            else
              {
                then = parse_exp();
              }

            expect_tok(":");

            ast::Exp* els = parse_exp();

            misc::Location loc = left->location_get() + els->location_get();
            left = new ast::ConditionalExp(loc, left, then, els);
          }

        else
          {
            ast::Exp* right = parse_exp(precedence(tok) + 1);
            if (right == nullptr)
              {
                std::clog << "No right member for binop\n";
              }

            misc::Location loc = left->location_get() + right->location_get();
            ast::binary_type type = get_binary_type(lexer::tok_repr(tok));

            left = new ast::BinaryExp(loc, type, left, right);
          }

        tok = peek_tok();
      }

    return left;
  }

  static bool is_binary(const lexer::Token& tok)
  {
    std::string c = tok_repr(tok);

    static const char* unary_tok[] = {
      "+",  "-",  "*",  "/",  "%",  "<<",  ">>",  "&", "|",  "^",  "&&",
      "||", "==", "!=", "<",  "<=", ">",   ">=",  "=", "+=", "-=", "*=",
      "/=", "%=", "&=", "|=", "^=", ">>=", "<<=", "?", 0};
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

}; // namespace parser
