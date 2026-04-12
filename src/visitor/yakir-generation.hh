#pragma once

#include "ast_visitor.hh"

#include "../yakir/yakir_node.hh"

#include <iostream>

namespace ast
{

  class YakirGeneration : public Visitor
  {
  public:
    YakirGeneration() {}

    yakir::Var* make_tmp_var();
    yakir::Label* make_tmp_label(std::string base = ".L");

    virtual void operator()(FunctionDec& e) override;
    virtual void operator()(BlockStatement& e) override;
    virtual void operator()(Var& e) override;
    virtual void operator()(VarDec& e) override;
    virtual void operator()(AssignExp& e) override;
    virtual void operator()(DecList& e) override;
    virtual void operator()(NumberExp& e) override;
    virtual void operator()(UnaryExp& e) override;
    virtual void operator()(BinaryExp& e) override;
    virtual void operator()(IncrementExp& e) override;
    virtual void operator()(DecrementExp& e) override;
    virtual void operator()(StringExp& e) override;
    virtual void operator()(ReturnExp& e) override;
    virtual void operator()(IfStatement& e) override;
    virtual void operator()(ConditionalExp& e) override;
    virtual void operator()(Goto& e) override;
    virtual void operator()(Label& e) override;
    virtual void operator()(While& e) override;
    virtual void operator()(DoWhile& e) override;
    virtual void operator()(For& e) override;
    virtual void operator()(Break& e) override;
    virtual void operator()(Continue& e) override;
    virtual void operator()(TypeName& e) override;

    template <typename AST, typename YAKIR> YAKIR* recurse(AST& t);
    template <typename AST, typename YAKIR> YAKIR* recurse(AST* t);

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
