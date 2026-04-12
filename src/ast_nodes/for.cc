#include "for.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  For::For(const misc::Location& loc,
           Statement* init,
           Exp* cond,
           Exp* post,
           Statement* body)
    : LoopStatement(loc)
    , init_(init)
    , cond_(cond)
    , post_(post)
    , body_(body)
  {}

  For::~For()
  {
    delete init_;
    delete cond_;
    delete post_;
    delete body_;
  }

  void For::accept(ConstVisitor& v) const { v(*this); }
  void For::accept(Visitor& v) { v(*this); }

} // namespace ast
