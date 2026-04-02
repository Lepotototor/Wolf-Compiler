#pragma once

#include "assembly_node.hh"

namespace assembly
{

  class Instruction : public AsmNode
  {
  public:
    Instruction(const misc::Location& loc)
      : AsmNode(loc)
    {}
  };

} // namespace assembly
