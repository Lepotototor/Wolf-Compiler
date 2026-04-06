#include "program.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Program::Program(const std::vector<FuncDef*> funcs)
    : AsmNode()
    , funcs_(funcs)
  {}

  Program::~Program()
  {
    for (auto func : funcs_)
      delete func;
  }

  void Program::accept(ConstVisitor& v) const { v(*this); }
  void Program::accept(Visitor& v) { v(*this); }

} // namespace assembly
