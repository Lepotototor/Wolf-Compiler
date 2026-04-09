#pragma once

#include "exp.hh"
#include "stmt.hh"

namespace ast
{

  class ExpressionStatement : public Statement
  {
  public:
    ExpressionStatement(Exp* exp);

    ~ExpressionStatement();

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Exp& exp_get() const { return *exp_; }
    Exp& exp_get() { return *exp_; }

  private:
    Exp* exp_;
  };

} // namespace ast
