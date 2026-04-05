#include "func_def.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  FuncDef::FuncDef(const misc::Location& loc,
                   const std::string& name,
                   const std::vector<Instruction*>& instructions)
    : YakirNode(loc)
    , name_(name)
    , ins_(instructions)
  {}

  FuncDef::~FuncDef()
  {
    for (Instruction* ins : ins_)
      delete ins;
  }

  void FuncDef::accept(ConstVisitor& v) const { v(*this); }
  void FuncDef::accept(Visitor& v) { v(*this); }

} // namespace yakir
