#include "decrement.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  DecrementExp::DecrementExp(const misc::Location& loc, Exp* exp, bool pre)
    : Exp(loc)
    , exp_(exp)
    , pre_(pre)
  {}

  DecrementExp::~DecrementExp() { delete exp_; }

  void DecrementExp::accept(ConstVisitor& v) const { v(*this); }
  void DecrementExp::accept(Visitor& v) { v(*this); }

} // namespace ast
