#pragma once

#include "assembly_node.hh"

namespace assembly
{

  class Instruction : public AsmNode
  {
  public:
    Instruction()
      : AsmNode()
    {}

    /// Accept a const visitor
    virtual void accept(ConstVisitor& v) const = 0;
    /// Accept a non-const visitor
    virtual void accept(Visitor& v) = 0;

    unsigned char ins_size_get() const { return ins_size_; }

  protected:
    unsigned char ins_size_;
  };

} // namespace assembly
