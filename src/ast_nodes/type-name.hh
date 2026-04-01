#pragma once

#include "type.hh"

namespace ast
{

  class TypeName : public Type
  {
  public:
    TypeName(const misc::Location& l, const std::string name)
      : Type(l)
      , name_(name)
    {}

    const std::string& name_get() const { return name_; }

  protected:
    std::string name_;
  };

} // namespace ast
