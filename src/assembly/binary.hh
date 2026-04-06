#pragma once

#include "instruction.hh"
#include "operand.hh"

#include "../ast_nodes/binary-exp.hh"

namespace assembly
{

  class Binary : public Instruction
  {
  public:
    Binary(ast::binary_type type, Operand* left, Operand* right);

    ~Binary() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    ast::binary_type type_get() const { return type_; }

    const Operand* left_get() const { return left_; }
    Operand* left_get() { return left_; }
    const Operand* right_get() const { return right_; }
    Operand* right_get() { return right_; }

  private:
    ast::binary_type type_;

    Operand* left_;
    Operand* right_;
  };

} // namespace assembly
