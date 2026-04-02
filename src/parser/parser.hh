#pragma once

#include "../ast_nodes/ast.hh"
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

    void parse();

    const lexer::Token& peek_tok();
    const lexer::Token& pop_tok();

    void expect_tok(const std::string& str);
    void expect_tok(char c);

    void mismatch_tok(const lexer::Token& tok, const std::string& exp);

    ast::Ast* program_get() { return program_; }

  private:
    // Able to get errors and program options
    driver::WolfDriver& wd_;

    std::queue<lexer::Token>& tokens_;

    ast::Ast* program_ = nullptr;
  };

} // namespace parser
