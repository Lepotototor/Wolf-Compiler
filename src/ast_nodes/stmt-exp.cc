#include "stmt-exp.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  ExpressionStatement::ExpressionStatement(Exp* exp)
    : Statement(exp->location_get())
    , exp_(exp)
  {}

  ExpressionStatement::~ExpressionStatement() { delete exp_; }

  void ExpressionStatement::accept(ConstVisitor& v) const { v(*this); }
  void ExpressionStatement::accept(Visitor& v) { v(*this); }

} // namespace ast
