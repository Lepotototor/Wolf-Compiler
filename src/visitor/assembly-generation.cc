#include "assembly-generation.hh"

#include "../assembly/allocate-stack.hh"
#include "../assembly/func_def.hh"
#include "../assembly/immediate.hh"
#include "../assembly/mov.hh"
#include "../assembly/program.hh"
#include "../assembly/register.hh"
#include "../assembly/ret.hh"
#include "../assembly/stack.hh"
#include "../assembly/unary.hh"

namespace yakir
{

  void AssemblyGeneration::operator()(const_t<Program>& e)
  {
    std::vector<assembly::FuncDef*> funcs;

    for (const yakir::FuncDef* func : e.funcs_get())
      {
        assembly::FuncDef* f = recurse<yakir::FuncDef, assembly::FuncDef>(func);
        funcs.emplace_back(f);
      }

    res_ = new assembly::Program(e.location_get(), funcs);
  }

  void AssemblyGeneration::operator()(const_t<Ret>& e)
  {
    if (e.val_get())
      {
        assembly::Operand* ope = recurse<Val, assembly::Operand>(e.val_get());
        assembly::Register* reg =
          new assembly::Register(e.location_get(), "eax");

        curr_func_.emplace_back(new assembly::Mov(e.location_get(), ope, reg));
      }

    curr_func_.emplace_back(new assembly::Ret(e.location_get()));
  }

  void AssemblyGeneration::operator()(const_t<FuncDef>& e)
  {
    curr_func_.clear();
    stack_size_ = 0;

    for (auto ins : e.instructions_get())
      {
        ins->accept(*this);
      }

    // TODO remove mov from stack to stack
    std::vector<assembly::Instruction*> instructions;
    for (assembly::Instruction* ins : curr_func_)
      {
        assembly::Mov* mov = dynamic_cast<assembly::Mov*>(ins);
        if (mov == nullptr)
          {
            instructions.emplace_back(ins);
            continue;
          }

        assembly::Stack* src = dynamic_cast<assembly::Stack*>(&mov->src_get());
        assembly::Stack* dst = dynamic_cast<assembly::Stack*>(&mov->dst_get());
        if (src == nullptr || dst == nullptr)
          {
            instructions.emplace_back(ins);
            continue;
          }

        assembly::Mov* first = new assembly::Mov(
          mov->location_get(),
          new assembly::Stack(src->location_get(), src->index_get()),
          new assembly::Register(e.location_get(), "r10d"));

        assembly::Mov* scnd = new assembly::Mov(
          mov->location_get(), new assembly::Register(e.location_get(), "r10d"),
          new assembly::Stack(dst->location_get(), dst->index_get()));

        delete mov;

        instructions.emplace_back(first);
        instructions.emplace_back(scnd);
      }

    // Use to allocate the stack as many tmp var we need
    // Allocate the stack is done at function start
    if (stack_size_ != 0)
      {
        assembly::AllocateStack* s =
          new assembly::AllocateStack(e.location_get(), stack_size_);
        instructions.emplace(instructions.begin(), s);
      }

    res_ = new assembly::FuncDef(e.location_get(), e.name_get(), instructions);
  }

  void AssemblyGeneration::operator()(const_t<Constant>& e)
  {
    res_ = new assembly::Immediate(e.location_get(), e.val_get());
  }

  void AssemblyGeneration::operator()(const_t<Var>& e)
  {
    if (var_loc_.contains(e.id_get()))
      {
        res_ = new assembly::Stack(e.location_get(), var_loc_[e.id_get()]);
      }
    else
      {
        stack_size_ += 4;
        var_loc_[e.id_get()] = -stack_size_;
        res_ = new assembly::Stack(e.location_get(), -stack_size_);
      }
  }

  void AssemblyGeneration::operator()(const_t<Unary>& e)
  {
    assembly::Operand* src = recurse<Val, assembly::Operand>(e.src_get());
    assembly::Operand* dst = recurse<Val, assembly::Operand>(e.dst_get());
    assembly::Operand* dst_copy = recurse<Val, assembly::Operand>(e.dst_get());

    assembly::Mov* mov = new assembly::Mov(e.location_get(), src, dst);
    assembly::Unary* un =
      new assembly::Unary(e.location_get(), e.type_get(), dst_copy);

    curr_func_.emplace_back(mov);
    curr_func_.emplace_back(un);
  }

} // namespace yakir
