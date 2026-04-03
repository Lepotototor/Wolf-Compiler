#include "ret.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  Ret::Ret(const misc::Location& loc, Mov* mov)
    : Instruction(loc)
    , mov_(mov)
  {}

  Ret::~Ret() { delete mov_; }

  void Ret::accept(ConstVisitor& v) const { v(*this); }
  void Ret::accept(Visitor& v) { v(*this); }

} // namespace yakir
