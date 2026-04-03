#include "func_def.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  FuncDef::FuncDef(const misc::Location& loc,
                   const std::string& name,
                   InsList* instructions)
    : YakirNode(loc)
    , name_(name)
    , ins_(instructions)
  {}

  FuncDef::~FuncDef() { delete ins_; }

  void FuncDef::accept(ConstVisitor& v) const { v(*this); }
  void FuncDef::accept(Visitor& v) { v(*this); }

} // namespace yakir
