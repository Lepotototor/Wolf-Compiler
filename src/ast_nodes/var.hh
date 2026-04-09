#pragma once

#include "bindable.hh"
#include "exp.hh"

namespace ast
{

  class Var
    : public Exp
    , public Bindable<ast::VarDec>
  {
  public:
    Var(const misc::Location& loc, const std::string& id);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const std::string& identifier_get() const { return identifier_; }
    void identifier_set(const std::string& id) { identifier_ = id; }

  private:
    std::string identifier_;
  };

} // namespace ast
