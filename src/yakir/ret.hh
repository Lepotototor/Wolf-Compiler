#pragma once

#include "instruction.hh"
#include "val.hh"

namespace yakir
{

  class Ret : public Instruction
  {
  public:
    Ret(Val* val);

    ~Ret() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Val* val_get() const { return val_; }
    Val* val_get() { return val_; }

  private:
    Val* val_ = nullptr;
  };

} // namespace yakir
