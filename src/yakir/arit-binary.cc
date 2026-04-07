#include "arit-binary.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{

  AritBinary::AritBinary(const misc::Location& loc,
                         ast::binary_type type,
                         Val* left,
                         Val* right,
                         Val* dst)
    : Binary(loc, type, left, right, dst)
  {}

  void AritBinary::accept(ConstVisitor& v) const { v(*this); }
  void AritBinary::accept(Visitor& v) { v(*this); }

} // namespace yakir
