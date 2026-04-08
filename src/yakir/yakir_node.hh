#pragma once

#include "all_nodes.hh"

namespace yakir
{
  class YakirNode
  {
  public:
    YakirNode() {}

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const = 0;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) = 0;

    virtual ~YakirNode() = default;

    YakirNode(const YakirNode&) = delete;
    const YakirNode& operator=(const YakirNode&) = delete;
  };

} // namespace yakir
