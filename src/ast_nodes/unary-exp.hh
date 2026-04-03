#pragma once

#include "exp.hh"

namespace ast
{

  enum unary_type
  {
    PLUS_U,
    MINUS_U,
    TILDE_U,
    NEGATE_U,
  };

  class UnaryExp : public Exp
  {
  public:
    UnaryExp(misc::Location& loc, unary_type type, Exp* exp);

    ~UnaryExp() override { delete exp_; }

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    unary_type type_get() const { return type_; }

    const Exp& exp_get() const { return *exp_; }
    Exp& exp_get() { return *exp_; }

  private:
    unary_type type_;

    Exp* exp_;
  };

} // namespace ast
