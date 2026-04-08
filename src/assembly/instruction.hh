#pragma once

#include "assembly_node.hh"

#include <map>
#include <string>

namespace assembly
{

  class Instruction : public AsmNode
  {
  public:
    Instruction(unsigned char ins_size)
      : AsmNode()
      , ins_size_(ins_size)
    {}

    /// Accept a const visitor
    virtual void accept(ConstVisitor& v) const = 0;
    /// Accept a non-const visitor
    virtual void accept(Visitor& v) = 0;

    std::string mnemo_get() const
    {
      static std::map<unsigned char, std::string> mnemonics_ = {
        {1, "b"}, {2, "w"}, {4, "l"}, {8, "q"}};

      return mnemonics_[ins_size_];
    }
    unsigned char ins_size_get() const { return ins_size_; }

  protected:
    unsigned char ins_size_;
  };

} // namespace assembly
