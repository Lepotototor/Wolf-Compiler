#pragma once

#include "exp.hh"

#include <vector>

namespace ast
{

  class ExpList : public Exp
  {
  public:
    ExpList(const misc::Location& l, const std::vector<Exp*>& exps);

    ~ExpList() override
    {
      for (Exp* exp : exps_)
        delete exp;
    }

    virtual void accept(ConstVisitor& v) const override;
    virtual void accept(Visitor& v) override;

    const std::vector<Exp*>& exps_get() const { return exps_; }
    std::vector<Exp*>& exps_get() { return exps_; }

  protected:
    std::vector<Exp*> exps_;
  };

} // namespace ast
