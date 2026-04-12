#pragma once

#include "exp.hh"
#include "for-init.hh"
#include "loop-stmt.hh"

namespace ast
{

  class For : public LoopStatement
  {
  public:
    For(const misc::Location& loc,
        ForInit* init,
        Exp* cond,
        Exp* post,
        Statement* body);

    ~For() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const ForInit* init_get() const { return init_; }
    ForInit* init_get() { return init_; }
    const Exp* cond_get() const { return cond_; }
    Exp* cond_get() { return cond_; }
    const Exp* post_get() const { return post_; }
    Exp* post_get() { return post_; }

    const Statement& body_get() const { return *body_; }
    Statement& body_get() { return *body_; }

  private:
    ForInit* init_;
    Exp* cond_;
    Exp* post_;

    Statement* body_;
  };

} // namespace ast
