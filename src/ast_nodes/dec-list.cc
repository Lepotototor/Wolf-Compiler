#include "dec-list.hh"

#include "../visitor/visitor.hh"

namespace ast
{

  DecList::DecList(const misc::Location& l,
                   const std::string& name,
                   const std::vector<Declaration*>& decs)
    : Declaration(l, name)
    , decs_(decs)
  {}

  void DecList::accept(ConstVisitor& v) const { v(*this); }
  void DecList::accept(Visitor& v) { v(*this); }
} // namespace ast
