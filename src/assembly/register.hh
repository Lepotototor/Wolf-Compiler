#pragma once

#include "operand.hh"

namespace assembly
{

  class Register : public Operand
  {
  public:
    Register(const misc::Location& loc, const std::string& name);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const std::string& name_get() const { return name_; }
    void set_name(const std::string& name) { name_ = name; }

  private:
    std::string name_;
  };

} // namespace assembly
