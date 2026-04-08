#include "label.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Label::Label(const std::string& name)
    : Instruction(0)
    , name_(name)
  {}

  void Label::accept(ConstVisitor& v) const { v(*this); }
  void Label::accept(Visitor& v) { v(*this); }

} // namespace assembly
