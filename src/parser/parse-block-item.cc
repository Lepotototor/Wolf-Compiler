#include "parser.hh"

#include "../ast_nodes/stmt.hh"

namespace parser
{

  ast::BlockItem* Parser::parse_block_item()
  {
    const lexer::Token& tok = peek_tok();

    if (tok == "int")
      {
        return parse_var_dec();
      }
    else
      {
        return parse_statement();
      }
  }

} // namespace parser
