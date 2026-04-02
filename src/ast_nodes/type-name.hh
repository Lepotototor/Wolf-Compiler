#pragma once

#include "type.hh"

namespace ast
{

  class TypeName : public Type
  {
  public:
    TypeName(const misc::Location& l, const std::string name);

    virtual void accept(ConstVisitor& v) const override;
    virtual void accept(Visitor& v) override;

    const std::string& name_get() const { return name_; }

  protected:
    std::string name_;
  };

} // namespace ast
