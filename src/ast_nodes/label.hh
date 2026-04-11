#pragma once

#include "stmt.hh"

namespace ast
{

  class Label : public Statement
  {
  public:
    Label(const misc::Location& loc, const std::string& name);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const std::string& name_get() const { return name_; }

  private:
    std::string name_;
  };

} // namespace ast
