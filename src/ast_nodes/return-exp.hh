#pragma once

#include "exp.hh"

namespace ast
{

  class ReturnExp : public Exp
  {
  public:
    ReturnExp(const misc::Location& l, Exp* return_val);

    ~ReturnExp() { delete return_val_; }

    virtual void accept(ConstVisitor& v) const override;
    virtual void accept(Visitor& v) override;

    const Exp* return_val_get() const { return return_val_; }
    Exp* return_val_get() { return return_val_; }

  protected:
    Exp* return_val_;
  };

} // namespace ast
