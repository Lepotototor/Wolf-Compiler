#include "../visitor/ast_visitor.hh"

#include "binary-exp.hh"

namespace ast
{

  BinaryExp::BinaryExp(misc::Location& loc,
                       binary_type type,
                       Exp* left,
                       Exp* right)
    : Exp(loc)
    , type_(type)
    , left_(left)
    , right_(right)
  {}

  void BinaryExp::accept(ConstVisitor& v) const { v(*this); }
  void BinaryExp::accept(Visitor& v) { v(*this); }

} // namespace ast
