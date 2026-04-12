#include "break.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  Break::Break(const misc::Location& loc)
    : Statement(loc)
  {}

  void Break::accept(ConstVisitor& v) const { v(*this); }
  void Break::accept(Visitor& v) { v(*this); }

} // namespace ast
