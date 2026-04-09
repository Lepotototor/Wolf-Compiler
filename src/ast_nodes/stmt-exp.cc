#include "stmt-exp.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  ExpressionStatement::ExpressionStatement(const misc::Location& loc, Exp* exp)
    : Statement(loc)
    , exp_(exp)
  {}

  void ExpressionStatement::accept(ConstVisitor& v) const { v(*this); }
  void ExpressionStatement::accept(Visitor& v) { v(*this); }

} // namespace ast
