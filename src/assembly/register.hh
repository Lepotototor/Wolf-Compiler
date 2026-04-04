#pragma once

#include "operand.hh"

namespace assembly
{

  class Register : public Operand
  {
  public:
    Register(const misc::Location& loc);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;
  };

} // namespace assembly
