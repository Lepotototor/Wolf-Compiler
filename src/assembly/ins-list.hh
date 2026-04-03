#pragma once

#include "instruction.hh"

#include <vector>

namespace assembly
{

  class InsList : public Instruction
  {
  public:
    InsList(const misc::Location& loc, std::vector<Instruction*> instructions);

    ~InsList() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    std::vector<Instruction*> instructions_get() { return instructions_; }
    const std::vector<Instruction*> instructions_get() const
    {
      return instructions_;
    }

  private:
    std::vector<Instruction*> instructions_;
  };

} // namespace assembly
