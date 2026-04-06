#include "parser.hh"

#include "../ast_nodes/dec-list.hh"
#include "../ast_nodes/function-dec.hh"

namespace parser
{
  ast::DecList* Parser::parser_external_declarations()
  {
    ENTER_PARSE_FUNC

    std::vector<ast::Declaration*> dec_list;

    for (lexer::Token tok = peek_tok(); tok != "END_OF_FILE"; tok = peek_tok())
      {
        dec_list.emplace_back(parse_function_dec());
      }

    return new ast::DecList(dec_list.front()->location_get()
                              + dec_list.back()->location_get(),
                            "Program", dec_list);
  }
} // namespace parser
