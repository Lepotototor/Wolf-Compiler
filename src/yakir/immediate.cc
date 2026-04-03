#include "immediate.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  Immediate::Immediate(const misc::Location& loc, const std::string& val)
    : Operand(loc)
    , val_(val)
  {}

  void Immediate::accept(ConstVisitor& v) const { v(*this); }
  void Immediate::accept(Visitor& v) { v(*this); }

} // namespace yakir
