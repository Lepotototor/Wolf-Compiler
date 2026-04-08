#include "copy.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  Copy::Copy(const misc::Location& loc, Val* src, Val* dst)
    : Instruction(loc)
    , src_(src)
    , dst_(dst)
  {}

  Copy::~Copy()
  {
    delete src_;
    delete dst_;
  }

  void Copy::accept(ConstVisitor& v) const { v(*this); }
  void Copy::accept(Visitor& v) { v(*this); }

} // namespace yakir
