#pragma once

#include "../ast_nodes/ast.hh"
#include "../ast_nodes/dec-list.hh"
#include "../driver/wolf-driver.hh"
#include "../lexer/lexer.hh"

namespace parser
{

  class Parser
  {
  public:
    Parser(driver::WolfDriver& wd, std::queue<lexer::Token>& tokens)
      : wd_(wd)
      , tokens_(tokens)
    {}

    void parse() { program_ = parser_external_declarations(); }

    const lexer::Token& peek_tok();
    const lexer::Token& pop_tok();

    const lexer::Token& expect_tok(const std::string& str);
    const lexer::Token& expect_tok(char c);

    void mismatch_tok(const lexer::Token& tok, const std::string& exp);
    void unexpected(const lexer::Token& tok);

    ast::Ast* program_get() { return program_; }

  private:
    /*      Parse Methods  Start    */
    ast::DecList* parser_external_declarations();
    ast::FunctionDec* parse_function_dec();

    ast::TypeName* parse_type();

    ast::Exp* parse_statement();
    ast::Exp* parse_return_statement();

    ast::Exp* parse_exp();
    /*      Parse Methods  End      */

  private:
    // Able to get errors and program options
    driver::WolfDriver& wd_;

    std::queue<lexer::Token>& tokens_;

    ast::Ast* program_ = nullptr;
  };

} // namespace parser
