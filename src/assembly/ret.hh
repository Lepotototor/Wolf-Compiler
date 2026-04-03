#pragma once

#include "instruction.hh"
#include "mov.hh"

namespace assembly
{

  class Ret : public Instruction
  {
  public:
    Ret(const misc::Location& loc, Mov* mov)
      : Instruction(loc)
      , mov_(mov)
    {}

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    Mov* mov_get();

  private:
    Mov* mov_ = nullptr;
  };

} // namespace assembly
