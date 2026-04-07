#include "cmp.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Cmp::Cmp(Operand* left, Operand* right)
    : Instruction()
    , left_(left)
    , right_(right)
  {}

  Cmp::~Cmp()
  {
    delete left_;
    delete right_;
  }

  void Cmp::accept(ConstVisitor& v) const { v(*this); }
  void Cmp::accept(Visitor& v) { v(*this); }

} // namespace assembly
