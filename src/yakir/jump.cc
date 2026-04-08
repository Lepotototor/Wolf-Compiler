#include "jump.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  Jump::Jump(const std::string& id)
    : Instruction()
    , id_(id)
  {}

  void Jump::accept(ConstVisitor& v) const { v(*this); }
  void Jump::accept(Visitor& v) { v(*this); }

} // namespace yakir
