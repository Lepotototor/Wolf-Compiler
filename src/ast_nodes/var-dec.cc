#include "var-dec.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  VarDec::VarDec(const misc::Location& loc, const std::string& name, Exp* init)
    : Declaration(loc, name)
    , init_(init)
  {}

  VarDec::~VarDec() { delete init_; }

  void VarDec::accept(ConstVisitor& v) const { v(*this); }
  void VarDec::accept(Visitor& v) { v(*this); }

} // namespace ast
