#pragma once

#include "instruction.hh"

namespace assembly
{

  class AllocateStack : public Instruction
  {
  public:
    AllocateStack(unsigned size);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    unsigned size_get() const { return size_; }
    void size_set(unsigned size) { size_ = size; }

  private:
    unsigned size_;
  };

} // namespace assembly
