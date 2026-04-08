#include "var.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  Var::Var(const misc::Location& loc, const std::string& id)
    : Exp(loc)
    , identifier_(id)
  {}

  void Var::accept(ConstVisitor& v) const { v(*this); }
  void Var::accept(Visitor& v) { v(*this); }

} // namespace ast
