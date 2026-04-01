#pragma once

#include "../misc/location.hh"

namespace ast
{

  class Ast : public misc::Locable
  {
  public:
    Ast(const misc::Location& l)
      : misc::Locable(l)
    {}

    virtual ~Ast() = default;

    // Disable copy of a node
    Ast(const Ast&) = delete;
    const Ast& operator=(const Ast&) = delete;
  };

} // namespace ast
