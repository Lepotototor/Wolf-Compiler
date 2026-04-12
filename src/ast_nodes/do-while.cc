#include "do-while.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  DoWhile::DoWhile(const misc::Location& loc, Exp* cond, Statement* body)
    : LoopStatement(loc)
    , cond_(cond)
    , body_(body)
  {}

  DoWhile::~DoWhile()
  {
    delete cond_;
    delete body_;
  }

  void DoWhile::accept(ConstVisitor& v) const { v(*this); }
  void DoWhile::accept(Visitor& v) { v(*this); }

} // namespace ast
