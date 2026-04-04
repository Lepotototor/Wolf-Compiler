#pragma once

#include "instruction.hh"
#include "mov.hh"

namespace assembly
{

  class Ret : public Instruction
  {
  public:
    Ret(const misc::Location& loc, Mov* mov);

    ~Ret() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Mov* mov_get() const { return mov_; }
    Mov* mov_get() { return mov_; }

  private:
    Mov* mov_ = nullptr;
  };

} // namespace assembly
