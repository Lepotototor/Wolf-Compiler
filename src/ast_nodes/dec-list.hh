#pragma once

#include "ast.hh"
#include "declaration.hh"

#include <vector>

namespace ast
{

  class DecList : public Ast
  {
  public:
    DecList(const misc::Location& l, const std::vector<Declaration*>& decs)
      : Ast(l)
      , decs_(decs)
    {}

    ~DecList() override
    {
      for (Declaration* dec : decs_)
        delete dec;
    }

    virtual void accept(ConstVisitor& v) const override { v(*this); }
    virtual void accept(Visitor& v) override { v(*this); }

    const std::vector<Declaration*>& decs_get() const { return decs_; }
    std::vector<Declaration*>& decs_get() { return decs_; }

  protected:
    std::vector<Declaration*> decs_;
  };

} // namespace ast
