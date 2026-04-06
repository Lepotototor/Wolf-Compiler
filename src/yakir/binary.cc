#include "binary.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{

  Binary::Binary(const misc::Location& loc,
                 ast::binary_type type,
                 Val* left,
                 Val* right,
                 Val* dst)
    : Instruction(loc)
    , type_(type)
    , left_(left)
    , right_(right)
    , dst_(dst)
  {}

  Binary::~Binary()
  {
    delete left_;
    delete right_;
    delete dst_;
  }

  void Binary::accept(ConstVisitor& v) const { v(*this); }
  void Binary::accept(Visitor& v) { v(*this); }

} // namespace yakir
