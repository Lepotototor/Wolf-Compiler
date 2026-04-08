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
    Register(register_type type, unsigned char size);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    register_type type_get() const { return type_; }
    unsigned char size_get() const { return size_; }

    const std::string& name_get() const { return registers_[type_][size_]; }

  private:
    static std::map<register_type, std::map<unsigned char, std::string>>
      registers_;

    enum register_type type_;

    unsigned char size_;
  };

} // namespace assembly
