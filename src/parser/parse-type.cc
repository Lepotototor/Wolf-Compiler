#include "parser.hh"

#include "../misc/format-helper.hh"

#include "../ast_nodes/type-name.hh"

namespace parser
{

  ast::TypeName* Parser::parse_type()
  {
    const lexer::Token& tok = pop_tok();
    if (tok == "void")
      {
        return new ast::TypeName(tok.location_get(), "void");
      }
    else if (tok == "int")
      {
        return new ast::TypeName(tok.location_get(), "int");
      }
    else if (tok == "char")
      {
        return new ast::TypeName(tok.location_get(), "char");
      }
    else
      {
        wd_.error_get() << misc::error_type::scan
                        << misc::bold(wd_.program_name) << ": " << misc::err()
                        << tok.location_get() << " Unknow type `"
                        << tok_repr(tok) << "`\n";

        return nullptr;
      }
  }

} // namespace parser
