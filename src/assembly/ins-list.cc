#include "ins-list.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  InsList::InsList(const misc::Location& loc,
                   std::vector<Instruction*> instructions)
    : Instruction(loc)
    , instructions_(instructions)
  {}

  void InsList::accept(ConstVisitor& v) const { v(*this); }
  void InsList::accept(Visitor& v) { v(*this); }

} // namespace assembly
