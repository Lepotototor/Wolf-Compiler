#pragma once

#include "operand.hh"

namespace assembly
{

  class Immediate : public Operand
  {
  public:
    Immediate(const misc::Location& loc, const std::string& val);

    const std::string& val_get() const { return val_; }

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

  private:
    std::string val_;
  };

} // namespace assembly
