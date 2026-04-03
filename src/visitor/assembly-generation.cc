#include "assembly-generation.hh"

#include "../ast_nodes/dec-list.hh"
#include "../ast_nodes/exp-list.hh"
#include "../ast_nodes/function-dec.hh"
#include "../ast_nodes/number-exp.hh"
#include "../ast_nodes/return-exp.hh"
#include "../ast_nodes/type-name.hh"

#include "../assembly/func_def.hh"
#include "../assembly/immediate.hh"
#include "../assembly/ins-list.hh"
#include "../assembly/mov.hh"
#include "../assembly/program.hh"
#include "../assembly/register.hh"
#include "../assembly/ret.hh"

using namespace assembly;

namespace ast
{

  void AsmGeneration::operator()(const DecList& e)
  {
    std::vector<FuncDef*> funcs;

    for (const auto& dec : e.decs_get())
      {
        FuncDef* func = recurse<Declaration, FuncDef>(dec);
        funcs.emplace_back(func);
      }

    res_ = new Program(e.location_get(), funcs);
  }

  void AsmGeneration::operator()(const FunctionDec& e)
  {
    InsList* ins = recurse<Exp, InsList>(e.body_get());
    res_ = new FuncDef(e.location_get(), e.name_get(), ins);
  }

  void AsmGeneration::operator()(const ExpList& e)
  {
    std::vector<Instruction*> ins;
    for (const auto& exp : e.exps_get())
      {
        Instruction* dec_ins = recurse<Exp, Instruction>(exp);

        ins.emplace_back(dec_ins);
      }

    res_ = new InsList(e.location_get(), ins);
  }

  void AsmGeneration::operator()(const NumberExp& e)
  {
    res_ = new Immediate(e.location_get(), e.val_get());
  }

  void AsmGeneration::operator()(const ReturnExp& e)
  {
    Operand* ope = recurse<Exp, Operand>(e.return_val_get());

    Mov* mov = nullptr;
    if (ope)
      {
        Register* reg = new Register{ope->location_get()};
        mov = new Mov(ope->location_get(), ope, reg);
      }

    res_ = new Ret(e.location_get(), mov);
  }

  void AsmGeneration::operator()(const StringExp&) {}
  void AsmGeneration::operator()(const TypeName&) {}

} // namespace ast
