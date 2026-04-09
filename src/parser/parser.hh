#pragma once

#include "../ast_nodes/ast.hh"
#include "../ast_nodes/dec-list.hh"
#include "../driver/wolf-driver.hh"
#include "../lexer/lexer.hh"
#include "../misc/defer.hh"

#define ENTER_PARSE_FUNC                                                       \
  misc::defer __end__parsing__defer__;                                         \
  if (wd_.parse_trace)                                                         \
    {                                                                          \
      std::string __func__name__ = __func__;                                   \
      deep_++;                                                                 \
      std::cout << "Enter " << __func__name__ << "\tdeep: " << deep_ << "\n";  \
      __end__parsing__defer__.func_set([&, __func__name__]() {                 \
        std::cout << "Exiting " << __func__name__ << "\n";                     \
        deep_--;                                                               \
      });                                                                      \
    }

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
    const lexer::Token pop_tok();

    const lexer::Token expect_tok(const std::string& str);
    const lexer::Token expect_tok(char c);

    void mismatch_tok(const lexer::Token& tok, const std::string& exp);
    void unexpected(const lexer::Token& tok);

    ast::Ast* program_get() { return program_; }

  private:
    /*      Parse Methods  Start    */
    ast::DecList* parser_external_declarations();
    ast::FunctionDec* parse_function_dec();

    ast::BlockItem* parse_block_item();

    ast::TypeName* parse_type();

    ast::Statement* parse_statement();
    ast::Statement* parse_return_statement();

    ast::Exp* parse_exp(unsigned predecence = 0);
    ast::Exp* parse_factor();

    ast::Declaration* parse_var_dec();
    /*      Parse Methods  End      */

    unsigned precedence(const lexer::Token& tok);

  private:
    // Able to get errors and program options
    driver::WolfDriver& wd_;

    // Use to debug informations
    unsigned deep_;

    std::queue<lexer::Token>& tokens_;

    ast::Ast* program_ = nullptr;
  };

} // namespace parser
