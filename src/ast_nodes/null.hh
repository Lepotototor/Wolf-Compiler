#pragma once

#include "stmt.hh"

namespace ast
{

  class Null : public Statement
  {
  public:
    Null(const misc::Location& loc);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;
  };

} // namespace ast
