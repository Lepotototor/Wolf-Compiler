#pragma once

#include "ast.hh"

namespace ast
{

  class Type : public Ast
  {
  public:
    Type(const misc::Location& l)
      : Ast(l)
    {}
  };

} // namespace ast
