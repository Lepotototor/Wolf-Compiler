#include "../visitor/ast_visitor.hh"

#include "unary-exp.hh"

namespace ast
{

  UnaryExp::UnaryExp(misc::Location& loc, unary_type type, Exp* exp)
    : Exp(loc)
    , type_(type)
    , exp_(exp)
  {}

  void UnaryExp::accept(ConstVisitor& v) const { v(*this); }
  void UnaryExp::accept(Visitor& v) { v(*this); }

} // namespace ast
