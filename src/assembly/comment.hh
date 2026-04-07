#pragma once

#include "instruction.hh"

#include <string>

namespace assembly
{

  class Comment : public Instruction
  {
  public:
    Comment(const std::string& val);

    const std::string& val_get() const { return val_; }

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

  private:
    std::string val_;
  };

} // namespace assembly
