#pragma once

#include "assembly_node.hh"

namespace assembly
{

  class Operand : public AsmNode
  {
  public:
    Operand() = default;

    /// Accept a const visitor
    virtual void accept(ConstVisitor& v) const = 0;
    /// Accept a non-const visitor
    virtual void accept(Visitor& v) = 0;
  };

} // namespace assembly
