#pragma once

#include "jump.hh"
#include "val.hh"

namespace yakir
{

  class JumpIfNotZero : public Jump
  {
  public:
    JumpIfNotZero(const misc::Location& loc, const std::string& id, Val* cond);

    ~JumpIfNotZero() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Val& cond_get() const { return *cond_; }
    Val& cond_get() { return *cond_; }

  private:
    Val* cond_;
  };

} // namespace yakir
