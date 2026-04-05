#include "pseudo.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Pseudo::Pseudo(const misc::Location& loc, const std::string& id)
    : Operand(loc)
    , id_(id)
  {}

  void Pseudo::accept(ConstVisitor& v) const { v(*this); }
  void Pseudo::accept(Visitor& v) { v(*this); }

} // namespace assembly
