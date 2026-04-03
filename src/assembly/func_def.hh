#pragma once

#include "assembly_node.hh"
#include "ins-list.hh"
#include "instruction.hh"

namespace assembly
{

  class FuncDef : public AsmNode
  {
  public:
    FuncDef(const misc::Location& loc,
            const std::string& name,
            InsList* instructions)
      : AsmNode(loc)
      , name_(name)
      , ins_(instructions)
    {}

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const std::string& name_get() const { return name_; }

    InsList* instructions_get() { return ins_; }
    const InsList* instructions_get() const { return ins_; }

  private:
    std::string name_;

    InsList* ins_;
  };

} // namespace assembly
