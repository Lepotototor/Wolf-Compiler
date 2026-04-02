#pragma once

#include "operand.hh"

namespace assembly
{

  class Register : public Operand
  {
  public:
    Register(const misc::Location& loc)
      : Operand(loc)
    {}
  };

} // namespace assembly
