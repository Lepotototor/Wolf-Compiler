#include "inc.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Inc::Inc(Operand* ope, unsigned char size)
    : Instruction(size)
    , ope_(ope)
  {}

  Inc::~Inc() { delete ope_; }

  void Inc::accept(ConstVisitor& v) const { v(*this); }
  void Inc::accept(Visitor& v) { v(*this); }

} // namespace assembly
