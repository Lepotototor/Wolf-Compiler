#pragma once

#include "exp.hh"

namespace ast
{

  class AssignExp : public Exp
  {
  public:
    AssignExp(const misc::Location& loc, Exp* lvalue, Exp* rvalue);

    ~AssignExp() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Exp& lvalue_get() const { return *lvalue_; }
    Exp& lvalue_get() { return *lvalue_; }
    const Exp& rvalue_get() const { return *rvalue_; }
    Exp& rvalue_get() { return *rvalue_; }

  private:
    Exp* lvalue_;
    Exp* rvalue_;
    ;
  };

} // namespace ast
