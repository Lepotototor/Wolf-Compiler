#include "ins-list.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{
  InsList::InsList(const misc::Location& loc,
                   std::vector<Instruction*> instructions)
    : Instruction(loc)
    , instructions_(instructions)
  {}

  InsList::~InsList()
  {
    for (auto ins : instructions_)
      delete ins;
  }

  void InsList::accept(ConstVisitor& v) const { v(*this); }
  void InsList::accept(Visitor& v) { v(*this); }

} // namespace yakir
