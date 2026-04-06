#include "binary.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Binary::Binary(ast::binary_type type, Operand* left, Operand* right)
    : Instruction()
    , type_(type)
    , left_(left)
    , right_(right)
  {}

  Binary::~Binary()
  {
    delete left_;
    delete right_;
  }

  void Binary::accept(ConstVisitor& v) const { v(*this); }
  void Binary::accept(Visitor& v) { v(*this); }

} // namespace assembly
