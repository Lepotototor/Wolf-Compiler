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

    yakir::Var* make_tmp_var();
    yakir::Label* make_tmp_label(std::string base = ".L");

    virtual void operator()(const FunctionDec& e) override;
    virtual void operator()(const BlockStatement& e) override;
    virtual void operator()(const Var& e) override;
    virtual void operator()(const VarDec& e) override;
    virtual void operator()(const AssignExp& e) override;
    virtual void operator()(const DecList& e) override;
    virtual void operator()(const NumberExp& e) override;
    virtual void operator()(const UnaryExp& e) override;
    virtual void operator()(const BinaryExp& e) override;
    virtual void operator()(const StringExp& e) override;
    virtual void operator()(const ReturnExp& e) override;
    virtual void operator()(const IfStatement& e) override;
    virtual void operator()(const ConditionalExp& e) override;
    virtual void operator()(const TypeName& e) override;

    template <typename AST, typename YAKIR> YAKIR* recurse(const AST& t);
    template <typename AST, typename YAKIR> YAKIR* recurse(const AST* t);

    yakir::YakirNode* res_get() { return res_; }

  private:
    yakir::YakirNode* res_;

    std::vector<yakir::Instruction*> curr_scope_;

    // Use to make unique identifiers
    unsigned id_count_ = 0;

    // Use to make unique labels
    unsigned lbl_count_ = 0;
  };

} // namespace ast

#include "yakir-generation.hxx"
