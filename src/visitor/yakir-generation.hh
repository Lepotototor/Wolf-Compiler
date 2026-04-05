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

    yakir::Var* make_tmp_var(const misc::Location& loc);

    virtual void operator()(const FunctionDec& e) override;
    virtual void operator()(const DecList& e) override;
    virtual void operator()(const ExpList& e) override;
    virtual void operator()(const NumberExp& e) override;
    virtual void operator()(const_t<UnaryExp>& e) override;
    virtual void operator()(const StringExp& e) override;
    virtual void operator()(const ReturnExp& e) override;
    virtual void operator()(const TypeName& e) override;

    template <typename AST, typename YAKIR> YAKIR* recurse(const AST& t);
    template <typename AST, typename YAKIR> YAKIR* recurse(const AST* t);

    yakir::YakirNode* res_get() { return res_; }

  private:
    yakir::YakirNode* res_;

    std::vector<yakir::Instruction*> curr_scope_;

    unsigned id_count_ = 0;
  };

} // namespace ast

#include "yakir-generation.hxx"
