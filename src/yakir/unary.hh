#pragma once

#include "instruction.hh"
#include "val.hh"

#include "../ast_nodes/unary-exp.hh"

namespace yakir
{

  class Unary : public Instruction
  {
  public:
    Unary(ast::unary_type type, Val* src, Val* dst);

    ~Unary() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    ast::unary_type type_get() const { return type_; }

    const Val& src_get() const { return *src_; }
    Val& src_get() { return *src_; }

    const Val& dst_get() const { return *dst_; }
    Val& dst_get() { return *dst_; }

  private:
    ast::unary_type type_;

    Val* src_;
    Val* dst_;
  };

} // namespace yakir
