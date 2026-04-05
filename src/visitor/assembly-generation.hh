#pragma once

#include "yakir_visitor.hh"

#include "../assembly/assembly_node.hh"

#include <iostream>

namespace yakir
{

  class AssemblyGeneration : public ConstVisitor
  {
  public:
    AssemblyGeneration() {}

    yakir::Var* make_tmp_var(const misc::Location& loc);

    virtual void operator()(const_t<Ret>& e);
    virtual void operator()(const_t<FuncDef>& e);
    virtual void operator()(const_t<Constant>& e);
    virtual void operator()(const_t<Var>& e);
    virtual void operator()(const_t<Unary>& e);
    virtual void operator()(const_t<Program>& e);

    template <typename YAKIR, typename ASM> ASM* recurse(const YAKIR& t);
    template <typename YAKIR, typename ASM> ASM* recurse(const YAKIR* t);

    assembly::AsmNode* res_get() { return res_; }

  private:
    assembly::AsmNode* res_;

    std::vector<assembly::Instruction*> curr_func_;

    unsigned id_count_ = 0;
  };

} // namespace yakir

#include "assembly-generation.hxx"
