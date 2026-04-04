#include "var.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  Var::Var(const misc::Location& loc, const std::string& id)
    : Val(loc)
    , id_(id)
  {}

  void Constant::accept(ConstVisitor& v) const { v(*this); }
  void Constant::accept(Visitor& v) { v(*this); }

} // namespace yakir
