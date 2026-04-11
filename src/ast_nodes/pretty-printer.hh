#pragma once

#include "../visitor/ast_visitor.hh"

#include <iostream>

namespace ast
{

  class PrettyPrinter : public ConstVisitor
  {
  public:
    PrettyPrinter(std::ostream& os)
      : ostr_(os)
    {}

    void newline();

    virtual void operator()(const FunctionDec& e) override;
    virtual void operator()(const BlockStatement& e) override;
    virtual void operator()(const DecList& e) override;
    virtual void operator()(const NumberExp& e) override;
    virtual void operator()(const UnaryExp& e) override;
    virtual void operator()(const BinaryExp& e) override;
    virtual void operator()(const IncrementExp& e) override;
    virtual void operator()(const DecrementExp& e) override;
    virtual void operator()(const StringExp& e) override;
    virtual void operator()(const Var& e) override;
    virtual void operator()(const VarDec& e) override;
    virtual void operator()(const Null& e) override;
    virtual void operator()(const AssignExp& e) override;
    virtual void operator()(const ReturnExp& e) override;
    virtual void operator()(const IfStatement& e) override;
    virtual void operator()(const ConditionalExp& e) override;
    virtual void operator()(const TypeName& e) override;

  private:
    std::ostream& ostr_;

    unsigned indent_ = 0;
  };

} // namespace ast

std::ostream& operator<<(std::ostream& os, const ast::Ast& e);
std::ostream& operator<<(std::ostream& os, const ast::Ast* e);
