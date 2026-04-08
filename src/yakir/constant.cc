#include "constant.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  Constant::Constant(const std::string& val)
    : Val()
    , val_(val)
  {}

  void Constant::accept(ConstVisitor& v) const { v(*this); }
  void Constant::accept(Visitor& v) { v(*this); }

} // namespace yakir
