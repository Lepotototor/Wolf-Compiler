#pragma once

#include "instruction.hh"
#include "val.hh"

namespace yakir
{
  enum unary_type
  {
    MINUS_U,
    TILDE_U,
    NEGATE_U,
  };

  class Unary : public Instruction
  {
  public:
    Unary(const misc::Location& loc, unary_type type, Val* src, Val* dst);

    ~Unary() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    unary_type type_get() const { return type_; }

    const Val& src_get() const { return *src_; }
    Val& src_get() { return *src_; }

    const Val& dst_get() const { return *dst_; }
    Val& dst_get() { return *dst_; }

  private:
    unary_type type_;

    Val* src_;
    Val* dst_;
  };

} // namespace yakir
