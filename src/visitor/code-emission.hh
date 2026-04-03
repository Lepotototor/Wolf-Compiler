#pragma once

#include "asm_visitor.hh"

#include <iostream>

namespace assembly
{

  class CodeEmit : public ConstVisitor
  {
  public:
    CodeEmit(std::ostream& os)
      : ostr_(os)
    {}

    virtual void operator()(const_t<InsList>& e) override;
    virtual void operator()(const_t<Ret>& e) override;
    virtual void operator()(const_t<Mov>& e) override;
    virtual void operator()(const_t<FuncDef>& e) override;
    virtual void operator()(const_t<Register>& e) override;
    virtual void operator()(const_t<Immediate>& e) override;
    virtual void operator()(const_t<Program>& e) override;

  private:
    std::ostream& ostr_;
  };

} // namespace assembly

std::ostream& operator<<(std::ostream& os, const assembly::AsmNode& e);
std::ostream& operator<<(std::ostream& os, const assembly::AsmNode* e);
