#pragma once

#include "yakir_node.hh"

namespace yakir
{

  class Instruction : public YakirNode
  {
  public:
    Instruction()
      : YakirNode()
    {}

    /// Accept a const visitor
    virtual void accept(ConstVisitor& v) const = 0;
    /// Accept a non-const visitor
    virtual void accept(Visitor& v) = 0;
  };

} // namespace yakir
