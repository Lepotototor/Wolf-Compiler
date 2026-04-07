#include "logical-binary.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{

  LogicalBinary::LogicalBinary(const misc::Location& loc,
                               ast::binary_type type,
                               Val* left,
                               Val* right,
                               Val* dst)
    : Binary(loc, type, left, right, dst)
  {}

  void LogicalBinary::accept(ConstVisitor& v) const { v(*this); }
  void LogicalBinary::accept(Visitor& v) { v(*this); }

} // namespace yakir
