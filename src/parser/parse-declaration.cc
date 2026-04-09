#include "parser.hh"

#include "../ast_nodes/exp.hh"
#include "../ast_nodes/type-name.hh"
#include "../ast_nodes/var-dec.hh"

namespace parser
{

  ast::Declaration* Parser::parse_var_dec()
  {
    ENTER_PARSE_FUNC

    // Variable type
    ast::TypeName* type = parse_type();

    // Var name
    const lexer::Token identifier = pop_tok();
    if (identifier.type() != lexer::IDENTIFIER_TOK)
      {
        mismatch_tok(identifier, "identifier");
      }

    lexer::Token tok = pop_tok();

    ast::Exp* init_exp = nullptr;

    if (tok == "=")
      {
        init_exp = parse_exp();
      }
    else if (tok != ";")
      {
        mismatch_tok(tok, "variable initalisation exp");
      }

    misc::Location loc = type->location_get()
      + (init_exp ? init_exp->location_get() : identifier.location_get());

    return new ast::VarDec(loc, identifier.val_get(), init_exp);
  }

} // namespace parser
