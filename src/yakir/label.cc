#include "label.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  Label::Label(const std::string& name)
    : Instruction()
    , name_(name)
  {}

  void Label::accept(ConstVisitor& v) const { v(*this); }
  void Label::accept(Visitor& v) { v(*this); }

} // namespace yakir
