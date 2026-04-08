#pragma once

#include "yakir_visitor.hh"

#include "../assembly/assembly_node.hh"

#include <iostream>
#include <string>
#include <unordered_map>

namespace yakir
{

  class AssemblyGeneration : public ConstVisitor
  {
  public:
    AssemblyGeneration() {}

    yakir::Var* make_tmp_var(const misc::Location& loc);

    virtual void operator()(const_t<Ret>& e);
    virtual void operator()(const_t<Label>& e);
    virtual void operator()(const_t<Jump>& e);
    virtual void operator()(const_t<JumpIfZero>& e);
    virtual void operator()(const_t<JumpIfNotZero>& e);
    virtual void operator()(const_t<FuncDef>& e);
    virtual void operator()(const_t<Constant>& e);
    virtual void operator()(const_t<Var>& e);
    virtual void operator()(const_t<Unary>& e);
    virtual void operator()(const_t<AritBinary>& e);
    virtual void operator()(const_t<LogicalBinary>& e);
    virtual void operator()(const_t<Program>& e);

    template <typename YAKIR, typename ASM> ASM* recurse(const YAKIR& t);
    template <typename YAKIR, typename ASM> ASM* recurse(const YAKIR* t);

    assembly::AsmNode* res_get() { return res_; }

  private:
    assembly::AsmNode* res_;

    // Use to get instructions inside function
    std::vector<assembly::Instruction*> curr_func_;
    // Increment each time we need a new variable in the stack
    // to know which stack size we need at func start
    unsigned stack_size_ = 0;

    // Get for each variable the stack location
    // We dont need scoped map because YAKIR use unique identifiers
    std::unordered_map<std::string, int> var_loc_;

    // Use to make unique identifiers
    unsigned id_count_ = 0;

    // Use to make unique labels
    unsigned lbl_count_ = 0;
  };

} // namespace yakir

#include "assembly-generation.hxx"
