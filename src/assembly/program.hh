#pragma once

#include "assembly_node.hh"
#include "func_def.hh"

#include <vector>

namespace assembly
{

  class Program : public AsmNode
  {
  public:
    Program(const misc::Location& loc, const std::vector<FuncDef*> funcs)
      : AsmNode(loc)
      , funcs_(funcs)
    {}

    const std::vector<FuncDef*>& funcs_get() const { return funcs_; }
    std::vector<FuncDef*>& funcs_get() { return funcs_; }

  private:
    std::vector<FuncDef*> funcs_;
  };

} // namespace assembly
