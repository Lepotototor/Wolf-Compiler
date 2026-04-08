#pragma once

#include "yakir_node.hh"

#include <string>
#include <vector>

namespace yakir
{

  class FuncDef : public YakirNode
  {
  public:
    FuncDef(const std::string& name,
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

} // namespace yakir
