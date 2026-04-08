#pragma once

#include "instruction.hh"
#include "val.hh"

namespace yakir
{

  class Copy : public Instruction
  {
  public:
    Copy(const misc::Location& loc, Val* src, Val* dst);

    ~Copy() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Val& src_get() const { return *src_; }
    Val& src_get() { return *src_; }
    const Val& dst_get() const { return *dst_; }
    Val& dst_get() { return *dst_; }

  private:
    Val* src_;
    Val* dst_;
  };

} // namespace yakir
