#include "number-exp.hh"

#include "../visitor/visitor.hh"

namespace ast
{

  NumberExp::NumberExp(const misc::Location& l, const std::string& val)
    : Exp(l)
    , val_(val)
  {}

  void NumberExp::accept(ConstVisitor& v) const { v(*this); }
  void NumberExp::accept(Visitor& v) { v(*this); }

} // namespace ast
