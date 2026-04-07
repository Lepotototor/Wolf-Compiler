#pragma once

#include "instruction.hh"
#include "operand.hh"

#include "../ast_nodes/binary-exp.hh"

namespace assembly
{

  class SetCC : public Instruction
  {
  public:
    SetCC(Operand* ope, ast::binary_type cond_type);

    ~SetCC();

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Operand& ope_get() const { return *ope_; }
    Operand& ope_get() { return *ope_; }

    ast::binary_type cond_type_get() const { return cond_type_; }

  private:
    Operand* ope_;

    ast::binary_type cond_type_;
  };

} // namespace assembly
