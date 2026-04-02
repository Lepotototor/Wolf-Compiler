#pragma once

#include "ast.hh"

namespace ast
{

  class Declaration : public Ast
  {
  public:
    Declaration(const misc::Location& l, const std::string& name)
      : Ast(l)
      , name_(name)
    {}

    /// Accept a const visitor
    virtual void accept(ConstVisitor& v) const = 0;
    /// Accept a non-const visitor
    virtual void accept(Visitor& v) = 0;

    const std::string& name_get() const { return name_; }

  protected:
    const std::string name_;
  };

} // namespace ast
