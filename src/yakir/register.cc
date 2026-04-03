#include "register.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  Register::Register(const misc::Location& loc)
    : Operand(loc)
  {}

  void Register::accept(ConstVisitor& v) const { v(*this); }
  void Register::accept(Visitor& v) { v(*this); }

} // namespace yakir
