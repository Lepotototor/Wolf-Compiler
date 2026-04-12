#pragma once

#include "ast.hh"
#include "for-init.hh"

namespace ast
{

  class Exp : public ForInit
  {
  public:
    Exp(const misc::Location& l)
      : ForInit(l)
    {}

    /// Accept a const visitor
    virtual void accept(ConstVisitor& v) const = 0;
    /// Accept a non-const visitor
    virtual void accept(Visitor& v) = 0;
  };

} // namespace ast
