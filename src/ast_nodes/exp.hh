#pragma once

#include "ast.hh"

namespace ast
{

  class Exp : public Ast
  {
  public:
    Exp(const misc::Location& l)
      : Ast(l)
    {}
  };

} // namespace ast
