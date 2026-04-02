#pragma once

#include "instruction.hh"

namespace assembly
{

  class Ret : public Instruction
  {
  public:
    Ret(const misc::Location& loc)
      : Instruction(loc)
    {}
  };

} // namespace assembly
