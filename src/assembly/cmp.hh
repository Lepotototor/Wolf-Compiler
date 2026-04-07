#pragma once

#include "instruction.hh"
#include "operand.hh"

namespace assembly
{

  class Cmp : public Instruction
  {
  public:
    Cmp(Operand* left, Operand* right);

    ~Cmp() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Operand& left_get() const { return *left_; }
    Operand& left_get() { return *left_; }
    const Operand& right_get() const { return *right_; }
    Operand& right_get() { return *right_; }

  private:
    Operand* left_;
    Operand* right_;
  };

} // namespace assembly
