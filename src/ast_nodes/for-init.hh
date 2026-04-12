#pragma once

#include "ast.hh"

namespace ast
{
  class ForInit : public Ast
  {
  public:
    ForInit(const misc::Location& loc)
      : Ast(loc)
    {}
  };
} // namespace ast
