#pragma once

#include "exp.hh"

namespace ast
{

  class Var : public Exp
  {
  public:
    Var(const misc::Location& loc, const std::string& id);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const std::string& identifier_get() const { return identifier_; }

  private:
    std::string identifier_;
  };

} // namespace ast
