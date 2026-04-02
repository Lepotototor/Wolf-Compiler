#pragma once

#include "declaration.hh"

#include <vector>

namespace ast
{

  class DecList : public Declaration
  {
  public:
    DecList(const misc::Location& l,
            const std::string& name,
            const std::vector<Declaration*>& decs);

    ~DecList() override
    {
      for (Declaration* dec : decs_)
        delete dec;
    }

    virtual void accept(ConstVisitor& v) const override;
    virtual void accept(Visitor& v) override;

    const std::vector<Declaration*>& decs_get() const { return decs_; }
    std::vector<Declaration*>& decs_get() { return decs_; }

  protected:
    std::vector<Declaration*> decs_;
  };

} // namespace ast
