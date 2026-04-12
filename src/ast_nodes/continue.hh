#pragma once

#include "bindable.hh"
#include "loop-stmt.hh"

namespace ast
{

  class Continue
    : public Statement
    , public Bindable<LoopStatement>
  {
  public:
    Continue(const misc::Location& loc);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;
  };

} // namespace ast
