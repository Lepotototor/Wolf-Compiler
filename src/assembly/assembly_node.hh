#pragma once

#include "all_nodes.hh"

namespace assembly
{
  class AsmNode
  {
  public:
    AsmNode() = default;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const = 0;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) = 0;

    virtual ~AsmNode() = default;

    AsmNode(const AsmNode&) = delete;
    const AsmNode& operator=(const AsmNode&) = delete;
  };

} // namespace assembly
