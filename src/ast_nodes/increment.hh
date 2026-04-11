#pragma once

#include "exp.hh"

namespace ast
{

  class IncrementExp : public Exp
  {
  public:
    IncrementExp(const misc::Location& loc, Exp* exp, bool pre);

    ~IncrementExp() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Exp& exp_get() const { return *exp_; }
    Exp& exp_get() { return *exp_; }

    bool pre_get() const { return pre_; }

  private:
    Exp* exp_;

    bool pre_;
  };

} // namespace ast
