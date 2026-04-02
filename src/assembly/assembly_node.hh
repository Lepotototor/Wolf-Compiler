#pragma once

#include "../misc/location.hh"

namespace assembly
{
  class AsmNode : public misc::Locable
  {
  public:
    AsmNode(const misc::Location& loc)
      : misc::Locable(loc)
    {}

    virtual ~AsmNode() = default;

    AsmNode(const AsmNode&) = delete;
    const AsmNode& operator=(const AsmNode&) = delete;
  };

} // namespace assembly
