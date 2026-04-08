#include "number-exp.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  NumberExp::NumberExp(const misc::Location& loc, const std::string& val)
    : Exp(loc)
    , val_(val)
  {}

  void NumberExp::accept(ConstVisitor& v) const { v(*this); }
  void NumberExp::accept(Visitor& v) { v(*this); }

} // namespace ast
