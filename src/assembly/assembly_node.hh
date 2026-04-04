#pragma once

#include "../misc/location.hh"
#include "all_nodes.hh"

namespace assembly
{
  class AsmNode : public misc::Locable
  {
  public:
    AsmNode(const misc::Location& loc)
      : misc::Locable(loc)
    {}

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const = 0;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) = 0;

    virtual ~AsmNode() = default;

    AsmNode(const AsmNode&) = delete;
    const AsmNode& operator=(const AsmNode&) = delete;
  };

} // namespace assembly
