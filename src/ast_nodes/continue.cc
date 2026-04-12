#include "break.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  Continue::Continue(const misc::Location& loc)
    : Statement(loc)
  {}

  void Continue::accept(ConstVisitor& v) const { v(*this); }
  void Continue::accept(Visitor& v) { v(*this); }

} // namespace ast
