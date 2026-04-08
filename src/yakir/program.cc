#include "program.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  Program::Program(const std::vector<FuncDef*> funcs)
    : YakirNode()
    , funcs_(funcs)
  {}

  Program::~Program()
  {
    for (auto func : funcs_)
      delete func;
  }

  void Program::accept(ConstVisitor& v) const { v(*this); }
  void Program::accept(Visitor& v) { v(*this); }

} // namespace yakir
