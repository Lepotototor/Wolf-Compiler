#pragma once

#include "assembly_node.hh"
#include "instruction.hh"

#include <vector>

namespace assembly
{

  class FuncDef : public AsmNode
  {
  public:
    FuncDef(const misc::Location& loc,
            const std::string& name,
            const std::vector<Instruction*>& instructions);

    ~FuncDef() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const std::string& name_get() const { return name_; }

    const std::vector<Instruction*>& instructions_get() const { return ins_; }
    std::vector<Instruction*>& instructions_get() { return ins_; }

  private:
    std::string name_;

    std::vector<Instruction*> ins_;
  };

} // namespace assembly
