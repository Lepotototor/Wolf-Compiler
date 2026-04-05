#include "allocate-stack.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  AllocateStack::AllocateStack(const misc::Location& loc, unsigned size)
    : Instruction(loc)
    , size_(size)
  {}

  void AllocateStack::accept(ConstVisitor& v) const { v(*this); }
  void AllocateStack::accept(Visitor& v) { v(*this); }

} // namespace assembly
