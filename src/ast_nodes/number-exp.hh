#pragma once

#include "exp.hh"

namespace ast
{

  class NumberExp : public Exp
  {
  public:
    NumberExp(const misc::Location& l, const std::string& val);

    virtual void accept(ConstVisitor& v) const override;
    virtual void accept(Visitor& v) override;

    const std::string& val_get() const { return val_; }

  protected:
    std::string val_;
  };

} // namespace ast
