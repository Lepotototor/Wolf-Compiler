#include "ret.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Ret::Ret()
    : Instruction()
  {}

  void Ret::accept(ConstVisitor& v) const { v(*this); }
  void Ret::accept(Visitor& v) { v(*this); }

} // namespace assembly
