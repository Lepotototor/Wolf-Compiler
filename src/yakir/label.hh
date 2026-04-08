#pragma once

#include "instruction.hh"

#include <string>

namespace yakir
{

  class Label : public Instruction
  {
  public:
    Label(const std::string& name);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const std::string& name_get() const { return name_; }

  private:
    const std::string name_;
  };

} // namespace yakir
