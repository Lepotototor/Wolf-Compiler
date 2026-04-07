#include "jumpcc.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  JumpCC::JumpCC(const std::string& id, ast::binary_type cond_type)
    : Jump(id)
    , cond_type_(cond_type)
  {}

  void JumpCC::accept(ConstVisitor& v) const { v(*this); }
  void JumpCC::accept(Visitor& v) { v(*this); }

} // namespace assembly
