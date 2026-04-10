#pragma once

#include "exp.hh"

namespace ast
{

  class ConditionalExp : public Exp
  {
  public:
    ConditionalExp(const misc::Location& loc, Exp* cond, Exp* then, Exp* els);

    ~ConditionalExp() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Exp& cond_get() const { return *cond_; }
    Exp& cond_get() { return *cond_; }
    const Exp& then_get() const { return *then_; }
    Exp& then_get() { return *then_; }
    const Exp& else_get() const { return *else_; }
    Exp& else_get() { return *else_; }

  private:
    Exp* cond_;
    Exp* then_;
    Exp* else_;
  };

} // namespace ast
