#include "constant.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  Constant::Constant(const misc::Location& loc, const std::string& val)
    : Val(loc)
    , val_(val)
  {}

  void Constant::accept(ConstVisitor& v) const { v(*this); }
  void Constant::accept(Visitor& v) { v(*this); }

} // namespace yakir
