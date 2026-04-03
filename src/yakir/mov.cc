#include "mov.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  Mov::Mov(const misc::Location& loc, Operand* src, Operand* dst)
    : Instruction(loc)
    , src_(src)
    , dst_(dst)
  {}

  Mov::~Mov()
  {
    delete src_;
    delete dst_;
  }

  void Mov::accept(ConstVisitor& v) const { v(*this); }
  void Mov::accept(Visitor& v) { v(*this); }

} // namespace yakir
