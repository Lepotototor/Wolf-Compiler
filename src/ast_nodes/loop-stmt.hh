#pragma once

#include "stmt.hh"

namespace ast
{

  class LoopStatement : public Statement
  {
  public:
    LoopStatement(const misc::Location& loc)
      : Statement(loc)
    {}

  private:
  };

} // namespace ast
