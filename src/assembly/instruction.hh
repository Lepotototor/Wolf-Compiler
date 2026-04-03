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

    /// Accept a const visitor
    virtual void accept(ConstVisitor& v) const = 0;
    /// Accept a non-const visitor
    virtual void accept(Visitor& v) = 0;
  };

} // namespace assembly
