#include "while.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  While::While(const misc::Location& loc, Exp* cond, Statement* body)
    : LoopStatement(loc)
    , cond_(cond)
    , body_(body)
  {}

  While::~While()
  {
    delete cond_;
    delete body_;
  }

  void While::accept(ConstVisitor& v) const { v(*this); }
  void While::accept(Visitor& v) { v(*this); }

} // namespace ast
