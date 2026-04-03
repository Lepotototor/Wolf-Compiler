#include "func_def.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  FuncDef::FuncDef(const misc::Location& loc,
                   const std::string& name,
                   InsList* instructions)
    : AsmNode(loc)
    , name_(name)
    , ins_(instructions)
  {}

  void FuncDef::accept(ConstVisitor& v) const { v(*this); }
  void FuncDef::accept(Visitor& v) { v(*this); }

} // namespace assembly
