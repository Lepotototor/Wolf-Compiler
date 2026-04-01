#pragma once

#include "exp.hh"

namespace ast
{

  class NumberExp : public Exp
  {
  public:
    NumberExp(const misc::Location& l, const std::string& val)
      : Exp(l)
      , val_(val)
    {}

    const std::string& val_get() const { return val_; }

  protected:
    std::string val_;
  };

} // namespace ast
