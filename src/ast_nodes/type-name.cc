#include "type-name.hh"

#include "../ast_visitor/visitor.hh"

namespace ast
{

  TypeName::TypeName(const misc::Location& l, const std::string name)
    : Type(l)
    , name_(name)
  {}

  void TypeName::accept(ConstVisitor& v) const { v(*this); }
  void TypeName::accept(Visitor& v) { v(*this); }

} // namespace ast
