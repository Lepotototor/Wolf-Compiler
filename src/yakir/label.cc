#include "label.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  Label::Label(const misc::Location& loc, const std::string& name)
    : Instruction(loc)
    , name_(name)
  {}

  void Label::accept(ConstVisitor& v) const { v(*this); }
  void Label::accept(Visitor& v) { v(*this); }

} // namespace yakir
