#include "if.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  IfStatement::IfStatement(const misc::Location& loc,
                           Exp* cond,
                           Statement* then,
                           Statement* els)
    : Statement(loc)
    , cond_(cond)
    , then_(then)
    , else_(els)
  {}

  IfStatement::~IfStatement()
  {
    delete cond_;
    delete then_;
    delete else_;
  }

  void IfStatement::accept(ConstVisitor& v) const { v(*this); }
  void IfStatement::accept(Visitor& v) { v(*this); }

} // namespace ast
