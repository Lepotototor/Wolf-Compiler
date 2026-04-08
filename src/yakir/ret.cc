#include "ret.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  Ret::Ret(Val* val)
    : Instruction()
    , val_(val)
  {}

  Ret::~Ret() { delete val_; }

  void Ret::accept(ConstVisitor& v) const { v(*this); }
  void Ret::accept(Visitor& v) { v(*this); }

} // namespace yakir
