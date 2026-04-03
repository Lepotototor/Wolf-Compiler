#include "immediate.hh"

#include "../visitor/visitor.hh"

namespace assembly
{
  void Immediate::accept(ConstVisitor& v) const { v(*this); }
  void Immediate::accept(Visitor& v) { v(*this); }

} // namespace assembly
