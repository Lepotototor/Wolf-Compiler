#pragma once

#include "yakir_node.hh"

namespace yakir
{

  class Val : public YakirNode
  {
  public:
    Val()
      : YakirNode()
    {}

    /// Accept a const visitor
    virtual void accept(ConstVisitor& v) const = 0;
    /// Accept a non-const visitor
    virtual void accept(Visitor& v) = 0;
  };

} // namespace yakir
