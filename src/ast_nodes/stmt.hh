#pragma once

#include "block-item.hh"

namespace ast
{

  class Statement : public BlockItem
  {
  public:
    Statement(const misc::Location& l)
      : BlockItem(l)
    {}

    /// Accept a const visitor
    virtual void accept(ConstVisitor& v) const = 0;
    /// Accept a non-const visitor
    virtual void accept(Visitor& v) = 0;
  };

} // namespace ast
