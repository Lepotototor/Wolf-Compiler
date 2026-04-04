#include "immediate.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Immediate::Immediate(const misc::Location& loc, const std::string& val)
    : Operand(loc)
    , val_(val)
  {}

  void Immediate::accept(ConstVisitor& v) const { v(*this); }
  void Immediate::accept(Visitor& v) { v(*this); }

} // namespace assembly
