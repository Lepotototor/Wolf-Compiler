#pragma once

#include "ast_visitor.hh"

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
    virtual void operator()(const DecList& e) override;
    virtual void operator()(const ExpList& e) override;
    virtual void operator()(const NumberExp& e) override;
    virtual void operator()(const UnaryExp& e) override;
    virtual void operator()(const StringExp& e) override;
    virtual void operator()(const ReturnExp& e) override;
    virtual void operator()(const TypeName& e) override;

  private:
    std::ostream& ostr_;

    unsigned indent_ = 0;
  };

} // namespace ast

std::ostream& operator<<(std::ostream& os, const ast::Ast& e);
std::ostream& operator<<(std::ostream& os, const ast::Ast* e);
