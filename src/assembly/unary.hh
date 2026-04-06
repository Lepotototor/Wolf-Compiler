#pragma once

#include "instruction.hh"
#include "operand.hh"

#include "../ast_nodes/unary-exp.hh"

namespace assembly
{

  class Unary : public Instruction
  {
  public:
    Unary(ast::unary_type type, Operand* ope);

    ~Unary() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    ast::unary_type type_get() const { return type_; }

    const Operand* ope_get() const { return ope_; }
    Operand* ope_get() { return ope_; }

  private:
    ast::unary_type type_;

    Operand* ope_;
  };

} // namespace assembly
