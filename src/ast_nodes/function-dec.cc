#include "function-dec.hh"

#include "../ast_visitor/visitor.hh"

namespace ast
{
  FunctionDec::FunctionDec(const misc::Location& l,
                           const std::string& name,
                           TypeName* return_type,
                           Exp* body)
    : Declaration(l, name)
    , return_type_(return_type)
    , body_(body)
  {}

  void FunctionDec::accept(ConstVisitor& v) const { v(*this); }
  void FunctionDec::accept(Visitor& v) { v(*this); }

} // namespace ast
