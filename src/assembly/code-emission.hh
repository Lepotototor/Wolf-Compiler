#pragma once

#include "../visitor/asm_visitor.hh"

#include <iostream>

namespace assembly
{

  class CodeEmit : public ConstVisitor
  {
  public:
    CodeEmit(std::ostream& os)
      : ostr_(os)
    {}

    virtual void operator()(const_t<Ret>& e);
    virtual void operator()(const_t<Mov>& e);
    virtual void operator()(const_t<Unary>& e);
    virtual void operator()(const_t<AllocateStack>& e);
    virtual void operator()(const_t<FuncDef>& e);
    virtual void operator()(const_t<Register>& e);
    virtual void operator()(const_t<Immediate>& e);
    virtual void operator()(const_t<Pseudo>& e);
    virtual void operator()(const_t<Stack>& e);
    virtual void operator()(const_t<Program>& e);

  private:
    std::ostream& ostr_;
  };

} // namespace assembly

std::ostream& operator<<(std::ostream& os, const assembly::AsmNode& e);
std::ostream& operator<<(std::ostream& os, const assembly::AsmNode* e);
