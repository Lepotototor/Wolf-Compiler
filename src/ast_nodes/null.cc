#include "null.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  Null::Null(const misc::Location& loc)
    : Statement(loc)
  {
    std::cerr << "Creating null node\n";
  }

  void Null::accept(ConstVisitor& v) const { v(*this); }
  void Null::accept(Visitor& v) { v(*this); }

} // namespace ast
