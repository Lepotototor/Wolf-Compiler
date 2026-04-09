#include "return.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  ReturnExp::ReturnExp(const misc::Location& l, Exp* return_val)
    : Statement(l)
    , return_val_(return_val)
  {}

  void ReturnExp::accept(ConstVisitor& v) const { v(*this); }
  void ReturnExp::accept(Visitor& v) { v(*this); }

} // namespace ast
