#include "jump-if-not-zero.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  JumpIfNotZero::JumpIfNotZero(const misc::Location& loc,
                               const std::string& id,
                               Val* cond)
    : Jump(loc, id)
    , cond_(cond)
  {}

  JumpIfNotZero::~JumpIfNotZero() { delete cond_; }

  void JumpIfNotZero::accept(ConstVisitor& v) const { v(*this); }
  void JumpIfNotZero::accept(Visitor& v) { v(*this); }

} // namespace yakir
