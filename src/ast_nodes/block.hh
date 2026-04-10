#pragma once

#include "block-item.hh"
#include "stmt.hh"

#include <vector>

namespace ast
{

  class BlockStatement : public Statement
  {
  public:
    BlockStatement(const misc::Location& loc,
                   const std::vector<BlockItem*> items);

    ~BlockStatement() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const std::vector<BlockItem*>& items_get() const { return items_; }

  private:
    std::vector<BlockItem*> items_;
  };

} // namespace ast
