#include "parser.hh"

#include "../ast_nodes/function-dec.hh"

namespace parser
{

  ast::FunctionDec* Parser::parse_function_dec()
  {
    ENTER_PARSE_FUNC

    // Function return type
    ast::TypeName* type = parse_type();

    // Function name
    const lexer::Token identifier = pop_tok();
    if (identifier.type() != lexer::IDENTIFIER_TOK)
      {
        mismatch_tok(identifier, "identifier");
      }

    // Function arguments
    expect_tok('(');

    const lexer::Token args = pop_tok();
    if (args == "void")
      {
        expect_tok(')');
      }
    else if (args != ')')
      {
        mismatch_tok(args, ")");
      }

    // Function body
    expect_tok('{');
    ast::Exp* body = parse_statement();
    expect_tok('}');

    return new ast::FunctionDec(type->location_get() + args.location_get(),
                                identifier.val_get(), type, body);
  }

} // namespace parser
