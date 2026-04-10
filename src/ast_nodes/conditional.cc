#include "conditional.hh"

#include "../visitor/ast_visitor.hh"

namespace ast
{
  ConditionalExp::ConditionalExp(const misc::Location& loc,
                                 Exp* cond,
                                 Exp* then,
                                 Exp* els)
    : Exp(loc)
    , cond_(cond)
    , then_(then)
    , else_(els)
  {}

  ConditionalExp::~ConditionalExp()
  {
    delete cond_;
    delete then_;
    delete else_;
  }

  void ConditionalExp::accept(ConstVisitor& v) const { v(*this); }
  void ConditionalExp::accept(Visitor& v) { v(*this); }

} // namespace ast
