#include "var-dec.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  VarDec::VarDec(const misc::Location& loc,
                 const std::string& name,
                 TypeName* type,
                 Exp* init)
    : Declaration(loc, name)
    , type_(type)
    , init_(init)
  {}

  VarDec::~VarDec() { delete init_; }

  void VarDec::accept(ConstVisitor& v) const { v(*this); }
  void VarDec::accept(Visitor& v) { v(*this); }

} // namespace ast
