#pragma once

#include "instruction.hh"

namespace assembly
{

  class Cdq : public Instruction
  {
  public:
    Cdq();

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

  private:
  };

} // namespace assembly
