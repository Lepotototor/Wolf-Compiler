#include "register.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Register::Register(const misc::Location& loc)
    : Operand(loc)
  {}

  void Register::accept(ConstVisitor& v) const { v(*this); }
  void Register::accept(Visitor& v) { v(*this); }

} // namespace assembly
