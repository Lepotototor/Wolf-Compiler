#include "jump.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Jump::Jump(const std::string& id)
    : Instruction(0)
    , id_(id)
  {}

  void Jump::accept(ConstVisitor& v) const { v(*this); }
  void Jump::accept(Visitor& v) { v(*this); }

} // namespace assembly
