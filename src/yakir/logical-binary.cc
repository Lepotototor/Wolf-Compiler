#include "logical-binary.hh"

#include "../visitor/yakir_visitor.hh"

namespace yakir
{

  LogicalBinary::LogicalBinary(ast::binary_type type,
                               Val* left,
                               Val* right,
                               Val* dst)
    : Binary(type, left, right, dst)
  {}

  void LogicalBinary::accept(ConstVisitor& v) const { v(*this); }
  void LogicalBinary::accept(Visitor& v) { v(*this); }

} // namespace yakir
