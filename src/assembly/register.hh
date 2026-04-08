#pragma once

#include "operand.hh"

#include <map>
#include <string>

namespace assembly
{

  enum register_type
  {
    AX = 0,
    BX,
    CX,
    DX,
    BP,
    SP,
    SI,
    DI,
    R8,
    R9,
    R10,
    R11,
    R12,
    R13,
    R14,
    R15,

  };

  class Register : public Operand
  {
  public:
    Register(const std::string& name);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const std::string& name_get() const { return name_; }
    void set_name(const std::string& name) { name_ = name; }

  private:
    static std::map<register_type, std::map<unsigned, std::string>> registers_;

    std::string name_;
  };

} // namespace assembly
