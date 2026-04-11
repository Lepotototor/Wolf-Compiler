#include "label.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  Label::Label(const misc::Location& loc, const std::string& name)
    : Statement(loc)
    , name_(name)
  {}

  void Label::accept(ConstVisitor& v) const { v(*this); }
  void Label::accept(Visitor& v) { v(*this); }

} // namespace ast
