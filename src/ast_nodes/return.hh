#pragma once

#include "exp.hh"
#include "stmt.hh"

namespace ast
{

  class ReturnExp : public Statement
  {
  public:
    ReturnExp(const misc::Location& l, Exp* return_val);

    ~ReturnExp() { delete return_val_; }

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Exp* return_val_get() const { return return_val_; }
    Exp* return_val_get() { return return_val_; }

  protected:
    Exp* return_val_;
  };

} // namespace ast
