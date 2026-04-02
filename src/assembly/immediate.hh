#pragma once

#include "operand.hh"

namespace assembly
{

  class Immediate : public Operand
  {
  public:
    Immediate(const misc::Location& loc, const std::string& val)
      : Operand(loc)
      , val_(val)
    {}

    const std::string& val_get() const { return val_; }

  private:
    std::string val_;
  };

} // namespace assembly
