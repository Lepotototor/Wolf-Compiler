#include "cdq.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Cdq::Cdq()
    : Instruction(0)
  {}

  void Cdq::accept(ConstVisitor& v) const { v(*this); }
  void Cdq::accept(Visitor& v) { v(*this); }

} // namespace assembly
