#pragma once

#include "instruction.hh"
#include "operand.hh"

namespace assembly
{

  class Mov : public Instruction
  {
  public:
    Mov(Operand* src, Operand* dst, unsigned char size);

    ~Mov() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Operand& src_get() const { return *src_; }
    Operand& src_get() { return *src_; }
    const Operand& dst_get() const { return *dst_; }
    Operand& dst_get() { return *dst_; }

  private:
    Operand* src_;
    Operand* dst_;
  };

} // namespace assembly
