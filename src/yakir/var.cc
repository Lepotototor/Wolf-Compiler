#include "var.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  Var::Var(const std::string& id)
    : Val()
    , id_(id)
  {}

  void Var::accept(ConstVisitor& v) const { v(*this); }
  void Var::accept(Visitor& v) { v(*this); }

} // namespace yakir
