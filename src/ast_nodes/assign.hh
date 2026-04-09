#pragma once

#include "exp.hh"
#include "var.hh"

namespace ast
{

  class AssignExp : public Exp
  {
  public:
    AssignExp(const misc::Location& loc, Var* lvalue, Exp* rvalue);

    ~AssignExp() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Var& lvalue_get() const { return *lvalue_; }
    Var& lvalue_get() { return *lvalue_; }
    const Exp& rvalue_get() const { return *rvalue_; }
    Exp& rvalue_get() { return *rvalue_; }

  private:
    Var* lvalue_;
    Exp* rvalue_;
    ;
  };

} // namespace ast
