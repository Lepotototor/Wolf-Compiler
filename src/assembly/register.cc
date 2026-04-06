#include "register.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Register::Register(const std::string& name)
    : Operand()
    , name_(name)
  {}

  void Register::accept(ConstVisitor& v) const { v(*this); }
  void Register::accept(Visitor& v) { v(*this); }

} // namespace assembly
