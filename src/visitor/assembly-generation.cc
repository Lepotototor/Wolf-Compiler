#include "assembly-generation.hh"

#include "../assembly/func_def.hh"
#include "../assembly/immediate.hh"
#include "../assembly/mov.hh"
#include "../assembly/program.hh"
#include "../assembly/pseudo.hh"
#include "../assembly/register.hh"
#include "../assembly/ret.hh"
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
          new assembly::Register(e.location_get(), "AX");

        curr_func_.emplace_back(new assembly::Mov(e.location_get(), ope, reg));
      }

    curr_func_.emplace_back(new assembly::Ret(e.location_get()));
  }

  void AssemblyGeneration::operator()(const_t<FuncDef>& e)
  {
    curr_func_.clear();

    for (auto ins : e.instructions_get())
      {
        ins->accept(*this);
      }

    res_ = new assembly::FuncDef(e.location_get(), e.name_get(), curr_func_);
  }

  void AssemblyGeneration::operator()(const_t<Constant>& e)
  {
    res_ = new assembly::Immediate(e.location_get(), e.val_get());
  }

  void AssemblyGeneration::operator()(const_t<Var>& e)
  {
    res_ = new assembly::Pseudo(e.location_get(), e.id_get());
  }

  void AssemblyGeneration::operator()(const_t<Unary>& e)
  {
    assembly::Operand* src = recurse<Val, assembly::Operand>(e.src_get());
    assembly::Operand* dst = recurse<Val, assembly::Operand>(e.dst_get());

    assembly::Mov* mov = new assembly::Mov(e.location_get(), src, dst);
    assembly::Unary* un =
      new assembly::Unary(e.location_get(), e.type_get(), dst);

    curr_func_.emplace_back(mov);
    curr_func_.emplace_back(un);
  }

} // namespace yakir
