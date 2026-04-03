#include "exp-list.hh"

#include "../visitor/visitor.hh"

namespace ast
{

  ExpList::ExpList(const misc::Location& l, const std::vector<Exp*>& exps)
    : Exp(l)
    , exps_(exps)
  {}

  void ExpList::accept(ConstVisitor& v) const { v(*this); }
  void ExpList::accept(Visitor& v) { v(*this); }

} // namespace ast
