#pragma once

#include "ast_visitor.hh"

#include "../yakir/yakir_node.hh"

#include <iostream>

namespace ast
{

  class YakirGeneration : public ConstVisitor
  {
  public:
    YakirGeneration() {}

    virtual void operator()(const FunctionDec& e) override;
    virtual void operator()(const DecList& e) override;
    virtual void operator()(const ExpList& e) override;
    virtual void operator()(const NumberExp& e) override;
    virtual void operator()(const StringExp& e) override;
    virtual void operator()(const ReturnExp& e) override;
    virtual void operator()(const TypeName& e) override;

    template <typename AST, typename YAKIR> YAKIR* recurse(const AST& t);
    template <typename AST, typename YAKIR> YAKIR* recurse(const AST* t);

    yakir::YakirNode* res_get() { return res_; }

  private:
    yakir::YakirNode* res_;
  };

} // namespace ast

#include "yakir-generation.hxx"
