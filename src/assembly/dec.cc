#include "dec.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Dec::Dec(Operand* ope, unsigned char size)
    : Instruction(size)
    , ope_(ope)
  {}

  Dec::~Dec() { delete ope_; }

  void Dec::accept(ConstVisitor& v) const { v(*this); }
  void Dec::accept(Visitor& v) { v(*this); }

} // namespace assembly
