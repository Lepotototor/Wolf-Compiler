#include "block.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{

  BlockStatement::BlockStatement(const misc::Location& loc,
                                 const std::vector<BlockItem*> items)
    : Statement(loc)
    , items_(items)
  {}

  BlockStatement::~BlockStatement()
  {
    for (const BlockItem* bi : items_)
      delete bi;
  }

  void BlockStatement::accept(ConstVisitor& v) const { v(*this); }
  void BlockStatement::accept(Visitor& v) { v(*this); }

} // namespace ast
