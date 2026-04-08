#include "jump-if-zero.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  JumpIfZero::JumpIfZero(const std::string& id, Val* cond)
    : Jump(id)
    , cond_(cond)
  {}

  JumpIfZero::~JumpIfZero() { delete cond_; }

  void JumpIfZero::accept(ConstVisitor& v) const { v(*this); }
  void JumpIfZero::accept(Visitor& v) { v(*this); }

} // namespace yakir
