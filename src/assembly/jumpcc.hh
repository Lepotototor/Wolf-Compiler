#pragma once

#include "jump.hh"

#include "../ast_nodes/binary-exp.hh"

namespace assembly
{

  class JumpCC : public Jump
  {
  public:
    JumpCC(const std::string& id, ast::binary_type cond_type);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    ast::binary_type cond_type_get() const { return cond_type_; }

  private:
    ast::binary_type cond_type_;
  };

} // namespace assembly
