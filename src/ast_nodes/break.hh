#pragma once

#include "bindable.hh"
#include "loop-stmt.hh"

namespace ast
{

  class Break
    : public Statement
    , public Bindable<LoopStatement>
  {
  public:
    Break(const misc::Location& loc);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;
  };

} // namespace ast
