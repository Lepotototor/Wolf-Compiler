#pragma once

#include "ast.hh"

namespace ast
{

  class BlockItem : public Ast
  {
  public:
    BlockItem(const misc::Location& loc)
      : Ast(loc)
    {}
  };

} // namespace ast
