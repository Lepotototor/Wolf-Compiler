#pragma once

#include "exp.hh"
#include "loop-stmt.hh"

namespace ast
{

  class For : public LoopStatement
  {
  public:
    For(const misc::Location& loc,
        Statement* init,
        Exp* cond,
        Exp* post,
        Statement* body);

    ~For() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Statement* init_get() const { return init_; }
    Statement* init_get() { return init_; }
    const Exp* cond_get() const { return cond_; }
    Exp* cond_get() { return cond_; }
    const Exp* post_get() const { return post_; }
    Exp* post_get() { return post_; }

    const Statement& body_get() const { return *body_; }
    Statement& body_get() { return *body_; }

  private:
    Statement* init_;
    Exp* cond_;
    Exp* post_;

    Statement* body_;
  };

} // namespace ast
