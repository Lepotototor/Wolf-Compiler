#pragma once

#include "assembly_node.hh"
#include "instruction.hh"

#include <vector>

namespace assembly
{

  class FuncDef : public AsmNode
  {
    FuncDef(const misc::Location& loc,
            const std::string& name,
            const std::vector<Instruction*> instructions)
      : AsmNode(loc)
      , name_(name)
      , instructions_(instructions)
    {}

    const std::string& name_get() const { return name_; }

    std::vector<Instruction*> instructions_get() { return instructions_; }
    const std::vector<Instruction*> instructions_get() const
    {
      return instructions_;
    }

  private:
    std::string name_;

    std::vector<Instruction*> instructions_;
  };

} // namespace assembly
