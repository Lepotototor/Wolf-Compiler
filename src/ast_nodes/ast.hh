#pragma once

#include "../ast_visitor/visitor.hh"
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

    /// Accept a const visitor
    virtual void accept(ConstVisitor& v) const = 0;
    /// Accept a non-const visitor
    virtual void accept(Visitor& v) = 0;

    // Disable copy of a node
    Ast(const Ast&) = delete;
    const Ast& operator=(const Ast&) = delete;
  };

} // namespace ast
