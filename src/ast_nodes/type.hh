#pragma once

#include "ast.hh"

namespace ast
{

  class Type : public Ast
  {
  public:
    Type(const misc::Location& l)
      : Ast(l)
    {}

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const = 0;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) = 0;
  };

} // namespace ast
