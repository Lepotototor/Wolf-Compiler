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

    Mov* mov_get();

  private:
    Mov* mov_ = nullptr;
  };

} // namespace assembly
