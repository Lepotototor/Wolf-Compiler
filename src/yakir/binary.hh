#pragma once

#include "instruction.hh"
#include "val.hh"

#include "../ast_nodes/binary-exp.hh"

namespace yakir
{

  class Binary : public Instruction
  {
  public:
    Binary(const misc::Location& loc,
           ast::binary_type type,
           Val* left,
           Val* right,
           Val* dst);

    ~Binary() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    ast::binary_type type_get() const { return type_; }

    const Val& left_get() const { return *left_; }
    Val& left_get() { return *left_; }
    const Val& right_get() const { return *right_; }
    Val& right_get() { return *right_; }

    const Val& dst_get() const { return *dst_; }
    Val& dst_get() { return *dst_; }

  private:
    ast::binary_type type_;

    Val* left_;
    Val* right_;
    Val* dst_;
  };

} // namespace yakir
