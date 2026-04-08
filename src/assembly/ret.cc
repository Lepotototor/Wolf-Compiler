#include "ret.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Ret::Ret()
    : Instruction(0)
  {}

  void Ret::accept(ConstVisitor& v) const { v(*this); }
  void Ret::accept(Visitor& v) { v(*this); }

} // namespace assembly
