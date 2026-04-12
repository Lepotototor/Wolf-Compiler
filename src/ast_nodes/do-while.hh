#pragma once

#include "exp.hh"
#include "loop-stmt.hh"

namespace ast
{

  class DoWhile : public LoopStatement
  {
  public:
    DoWhile(const misc::Location& loc, Exp* cond, Statement* body);

    ~DoWhile() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Exp& cond_get() const { return *cond_; }
    Exp& cond_get() { return *cond_; }

    const Statement& body_get() const { return *body_; }
    Statement& body_get() { return *body_; }

  private:
    Exp* cond_;

    Statement* body_;
  };

} // namespace ast
