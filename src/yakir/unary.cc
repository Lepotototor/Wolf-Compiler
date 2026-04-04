#include "unary.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{

  Unary::Unary(const misc::Location& loc, unary_type type, Val* src, Val* dst)
    : Instruction(loc)
    , type_(type)
    , src_(src)
    , dst_(dst)
  {}

  Unary::~Unary()
  {
    delete src_;
    delete dst_;
  }

  void Unary::accept(ConstVisitor& v) const { v(*this); }
  void Unary::accept(Visitor& v) { v(*this); }

} // namespace yakir
