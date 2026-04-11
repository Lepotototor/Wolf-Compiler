#pragma once

#include "instruction.hh"
#include "operand.hh"

namespace assembly
{

  class Inc : public Instruction
  {
  public:
    Inc(Operand* ope, unsigned char size);

    ~Inc() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Operand& ope_get() const { return *ope_; }
    Operand& ope_get() { return *ope_; }

  private:
    Operand* ope_;
  };

} // namespace assembly
