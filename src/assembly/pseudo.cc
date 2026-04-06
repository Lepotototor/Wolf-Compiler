#include "pseudo.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Pseudo::Pseudo(const std::string& id)
    : Operand()
    , id_(id)
  {}

  void Pseudo::accept(ConstVisitor& v) const { v(*this); }
  void Pseudo::accept(Visitor& v) { v(*this); }

} // namespace assembly
