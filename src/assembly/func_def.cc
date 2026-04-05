#include "func_def.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  FuncDef::FuncDef(const misc::Location& loc,
                   const std::string& name,
                   const std::vector<Instruction*>& instructions)
    : AsmNode(loc)
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

} // namespace assembly
