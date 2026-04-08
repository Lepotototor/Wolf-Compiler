#include "assign.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  AssignExp::AssignExp(const misc::Location& loc, Exp* lvalue, Exp* rvalue)
    : Exp(loc)
    , lvalue_(lvalue)
    , rvalue_(rvalue)
  {}

  AssignExp::~AssignExp()
  {
    delete lvalue_;
    delete rvalue_;
  }

  void AssignExp::accept(ConstVisitor& v) const { v(*this); }
  void AssignExp::accept(Visitor& v) { v(*this); }

} // namespace ast
