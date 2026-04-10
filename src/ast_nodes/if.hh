#pragma once

#include "exp.hh"
#include "stmt.hh"

namespace ast
{

  class IfStatement : public Statement
  {
  public:
    IfStatement(const misc::Location& loc,
                Exp* cond,
                Statement* then,
                Statement* els);

    ~IfStatement() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Exp& cond_get() const { return *cond_; }
    Exp& cond_get() { return *cond_; }
    const Statement& then_get() const { return *then_; }
    Statement& then_get() { return *then_; }
    const Statement* else_get() const { return else_; }
    Statement* else_get() { return else_; }

  private:
    Exp* cond_;
    Statement* then_;
    Statement* else_;
  };

} // namespace ast
