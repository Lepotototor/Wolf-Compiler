#pragma once

#include "exp.hh"

namespace ast
{

  class ReturnExp : public Exp
  {
  public:
    ReturnExp(const misc::Location& l, Exp* return_val)
      : Exp(l)
      , return_val_(return_val)
    {}

    ~ReturnExp() { delete return_val_; }

    virtual void accept(ConstVisitor& v) const override { v(*this); }
    virtual void accept(Visitor& v) override { v(*this); }

    const Exp* return_val_get() const { return return_val_; }
    Exp* return_val_get() { return return_val_; }

  protected:
    Exp* return_val_;
  };

} // namespace ast
