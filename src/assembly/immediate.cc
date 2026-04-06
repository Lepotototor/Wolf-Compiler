#include "immediate.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Immediate::Immediate(const std::string& val)
    : Operand()
    , val_(val)
  {}

  void Immediate::accept(ConstVisitor& v) const { v(*this); }
  void Immediate::accept(Visitor& v) { v(*this); }

} // namespace assembly
