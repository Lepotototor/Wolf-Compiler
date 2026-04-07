#include "setcc.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{

  SetCC::SetCC(Operand* ope, ast::binary_type cond_type)
    : Instruction()
    , ope_(ope)
    , cond_type_(cond_type)
  {}

  SetCC::~SetCC() { delete ope_; }

  void SetCC::accept(ConstVisitor& v) const { v(*this); }
  void SetCC::accept(Visitor& v) { v(*this); }

} // namespace assembly
