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

    const std::string& name_get() const { return name_; }

  protected:
    const std::string name_;
  };

} // namespace ast
