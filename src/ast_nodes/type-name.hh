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

    virtual void accept(ConstVisitor& v) const override { v(*this); }
    virtual void accept(Visitor& v) override { v(*this); }

    const std::string& name_get() const { return name_; }

  protected:
    std::string name_;
  };

} // namespace ast
