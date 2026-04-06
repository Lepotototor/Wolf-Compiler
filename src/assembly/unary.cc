#include "unary.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Unary::Unary(ast::unary_type type, Operand* ope)
    : Instruction()
    , type_(type)
    , ope_(ope)
  {}

  Unary::~Unary() { delete ope_; }

  void Unary::accept(ConstVisitor& v) const { v(*this); }
  void Unary::accept(Visitor& v) { v(*this); }

} // namespace assembly
