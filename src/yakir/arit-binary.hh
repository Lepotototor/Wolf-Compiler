#pragma once

#include "binary.hh"
#include "val.hh"

#include "../ast_nodes/binary-exp.hh"

namespace yakir
{

  class AritBinary : public Binary
  {
  public:
    AritBinary(const misc::Location& loc,
               ast::binary_type type,
               Val* left,
               Val* right,
               Val* dst);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;
  };

} // namespace yakir
