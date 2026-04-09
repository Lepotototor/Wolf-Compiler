#pragma once

#include "block-item.hh"

namespace ast
{

  class Declaration : public BlockItem
  {
  public:
    Declaration(const misc::Location& l, const std::string& name)
      : BlockItem(l)
      , name_(name)
    {}

    /// Accept a const visitor
    virtual void accept(ConstVisitor& v) const = 0;
    /// Accept a non-const visitor
    virtual void accept(Visitor& v) = 0;

    const std::string& name_get() const { return name_; }
    void name_set(const std::string& name) { name_ = name; }

  protected:
    std::string name_;
  };

} // namespace ast
