#pragma once

#include "ast_visitor.hh"

#include "../assembly/assembly_node.hh"

#include <iostream>

namespace ast
{

  class AsmGeneration : public ConstVisitor
  {
  public:
    AsmGeneration() {}

    virtual void operator()(const FunctionDec& e) override;
    virtual void operator()(const DecList& e) override;
    virtual void operator()(const ExpList& e) override;
    virtual void operator()(const NumberExp& e) override;
    virtual void operator()(const StringExp& e) override;
    virtual void operator()(const ReturnExp& e) override;
    virtual void operator()(const TypeName& e) override;

    template <typename AST, typename ASM> ASM* recurse(const AST& t);
    template <typename AST, typename ASM> ASM* recurse(const AST* t);

    assembly::AsmNode* res_get() { return res_; }

  private:
    assembly::AsmNode* res_;
  };

} // namespace ast

#include "assembly-generation.hxx"
