#include "stack.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Stack::Stack(int index)
    : Operand()
    , index_(index)
  {}

  void Stack::accept(ConstVisitor& v) const { v(*this); }
  void Stack::accept(Visitor& v) { v(*this); }
} // namespace assembly
