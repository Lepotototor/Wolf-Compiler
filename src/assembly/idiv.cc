#include "idiv.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Idiv::Idiv(Operand* ope)
    : Instruction()
    , ope_(ope)
  {}

  Idiv::~Idiv() { delete ope_; }

  void Idiv::accept(ConstVisitor& v) const { v(*this); }
  void Idiv::accept(Visitor& v) { v(*this); }

} // namespace assembly
