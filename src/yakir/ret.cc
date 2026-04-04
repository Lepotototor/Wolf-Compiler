#include "ret.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  Ret::Ret(const misc::Location& loc, Val* val)
    : Instruction(loc)
    , val_(val)
  {}

  Ret::~Ret() { delete val_; }

  void Ret::accept(ConstVisitor& v) const { v(*this); }
  void Ret::accept(Visitor& v) { v(*this); }

} // namespace yakir
