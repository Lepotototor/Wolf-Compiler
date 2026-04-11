#include "decrement.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{

  Decrement::Decrement(Val* val)
    : val_(val)
  {}

  Decrement::~Decrement() { delete val_; }

  void Decrement::accept(ConstVisitor& v) const { v(*this); }
  void Decrement::accept(Visitor& v) { v(*this); }

} // namespace yakir
