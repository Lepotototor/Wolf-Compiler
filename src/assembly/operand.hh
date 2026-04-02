#pragma once

#include "assembly_node.hh"

namespace assembly
{

  class Operand : public AsmNode
  {
  public:
    Operand(const misc::Location& loc)
      : AsmNode(loc)
    {}
  };

} // namespace assembly
