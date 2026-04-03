#include "mov.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
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

} // namespace assembly
