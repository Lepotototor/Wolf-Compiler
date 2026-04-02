#include "parser.hh"

#include "../ast_nodes/number-exp.hh"

namespace parser
{

  ast::Exp* Parser::parse_exp()
  {
    const lexer::Token tok = peek_tok();

    if (tok.type() == lexer::NUM_TOK)
      {
        pop_tok();
        return new ast::NumberExp(tok.location_get(), tok.val_get());
      }
    else
      {
        std::clog << "Parse EXP unknow exp";
        return nullptr;
      }
  }

}; // namespace parser
