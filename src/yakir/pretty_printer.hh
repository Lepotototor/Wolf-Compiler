#pragma once

#include "../visitor/yakir_visitor.hh"

#include <iostream>

namespace yakir
{

  class PrettyPrinter : public ConstVisitor
  {
  public:
    PrettyPrinter(std::ostream& os)
      : ostr_(os)
    {}

    virtual void operator()(const_t<Ret>& e) override;
    virtual void operator()(const_t<Copy>& e) override;
    virtual void operator()(const_t<Label>& e) override;
    virtual void operator()(const_t<Jump>& e) override;
    virtual void operator()(const_t<JumpIfZero>& e) override;
    virtual void operator()(const_t<JumpIfNotZero>& e) override;
    virtual void operator()(const_t<Unary>& e) override;
    virtual void operator()(const_t<AritBinary>& e) override;
    virtual void operator()(const_t<LogicalBinary>& e) override;
    virtual void operator()(const_t<Increment>& e) override;
    virtual void operator()(const_t<Decrement>& e) override;
    virtual void operator()(const_t<FuncDef>& e) override;
    virtual void operator()(const_t<Constant>& e) override;
    virtual void operator()(const_t<Var>& e) override;
    virtual void operator()(const_t<Program>& e) override;

  private:
    std::ostream& ostr_;
  };

} // namespace yakir

std::ostream& operator<<(std::ostream& os, const yakir::YakirNode& e);
std::ostream& operator<<(std::ostream& os, const yakir::YakirNode* e);
