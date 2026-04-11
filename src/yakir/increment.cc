#include "increment.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{

  Increment::Increment(Val* val)
    : val_(val)
  {}

  Increment::~Increment() { delete val_; }

  void Increment::accept(ConstVisitor& v) const { v(*this); }
  void Increment::accept(Visitor& v) { v(*this); }

} // namespace yakir
