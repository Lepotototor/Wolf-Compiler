#include "comment.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Comment::Comment(const std::string& val)
    : Instruction(0)
    , val_(val)
  {}

  void Comment::accept(ConstVisitor& v) const { v(*this); }
  void Comment::accept(Visitor& v) { v(*this); }

} // namespace assembly
