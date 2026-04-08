#include "jump.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  Jump::Jump(const misc::Location& loc, const std::string& id)
    : Instruction(loc)
    , id_(id)
  {}

  void Jump::accept(ConstVisitor& v) const { v(*this); }
  void Jump::accept(Visitor& v) { v(*this); }

} // namespace yakir
