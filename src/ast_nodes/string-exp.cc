#include "string-exp.hh"

#include "../visitor/visitor.hh"

namespace ast
{

  StringExp::StringExp(const misc::Location& l, const std::string& val)
    : Exp(l)
    , val_(val)
  {}

  void StringExp::accept(ConstVisitor& v) const { v(*this); }
  void StringExp::accept(Visitor& v) { v(*this); }

} // namespace ast
