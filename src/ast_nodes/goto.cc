#include "goto.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  Goto::Goto(const misc::Location& loc, const std::string& id)
    : Statement(loc)
    , id_(id)
  {}

  void Goto::accept(ConstVisitor& v) const { v(*this); }
  void Goto::accept(Visitor& v) { v(*this); }

} // namespace ast
