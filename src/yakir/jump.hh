#pragma once

#include "instruction.hh"

namespace yakir
{

  class Jump : public Instruction
  {
  public:
    Jump(const misc::Location& loc, const std::string& id);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const std::string& id_get() const { return id_; }

  protected:
    std::string id_;
  };

} // namespace yakir
