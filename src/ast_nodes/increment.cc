#include "increment.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  IncrementExp::IncrementExp(const misc::Location& loc, Exp* exp, bool pre)
    : Exp(loc)
    , exp_(exp)
    , pre_(pre)
  {}

  IncrementExp::~IncrementExp() { delete exp_; }

  void IncrementExp::accept(ConstVisitor& v) const { v(*this); }
  void IncrementExp::accept(Visitor& v) { v(*this); }

} // namespace ast
