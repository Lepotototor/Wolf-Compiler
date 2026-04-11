#pragma once

#include "stmt.hh"

namespace ast
{

  class Goto : public Statement
  {
  public:
    Goto(const misc::Location& loc, const std::string& id);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const std::string& id_get() const { return id_; }

  private:
    std::string id_;
  };

} // namespace ast
