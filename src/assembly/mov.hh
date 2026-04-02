#pragma once

#include "instruction.hh"
#include "operand.hh"

namespace assembly
{

  class Mov : public Instruction
  {
  public:
    Mov(const misc::Location& loc, Operand* src, Operand* dst)
      : Instruction(loc)
      , src_(src)
      , dst_(dst)
    {}

    const Operand& src_get() const { return *src_; }
    const Operand& dst_get() const { return *dst_; }

  private:
    Operand* src_;
    Operand* dst_;
  };

} // namespace assembly
