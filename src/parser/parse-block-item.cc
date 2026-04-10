#include "parser.hh"

#include "../ast_nodes/block.hh"
#include "../ast_nodes/stmt.hh"

namespace parser
{

  ast::BlockStatement* Parser::parse_block_statement()
  {
    expect_tok("{");

    std::vector<ast::BlockItem*> items;

    lexer::Token tok = peek_tok();

    while (tok != "}")
      {
        ast::BlockItem* bi = parse_block_item();
        items.emplace_back(bi);

        tok = peek_tok();
      }

    expect_tok("}");

    misc::Location loc = items.size() == 0
      ? tok.location_get()
      : items.front()->location_get() + items.back()->location_get();

    return new ast::BlockStatement(loc, items);
  }

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
