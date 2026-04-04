#include "yakir-generation.hh"

#include "../ast_nodes/dec-list.hh"
#include "../ast_nodes/exp-list.hh"
#include "../ast_nodes/function-dec.hh"
#include "../ast_nodes/number-exp.hh"
#include "../ast_nodes/return-exp.hh"
#include "../ast_nodes/type-name.hh"

#include "../yakir/constant.hh"
#include "../yakir/func_def.hh"
#include "../yakir/ins-list.hh"
#include "../yakir/program.hh"
#include "../yakir/ret.hh"

using namespace yakir;

namespace ast
{

  void YakirGeneration::operator()(const DecList& e)
  {
    std::vector<FuncDef*> funcs;

    for (const auto& dec : e.decs_get())
      {
        FuncDef* func = recurse<Declaration, FuncDef>(dec);
        funcs.emplace_back(func);
      }

    res_ = new Program(e.location_get(), funcs);
  }

  void YakirGeneration::operator()(const FunctionDec& e)
  {
    InsList* ins = recurse<Exp, InsList>(e.body_get());
    res_ = new FuncDef(e.location_get(), e.name_get(), ins);
  }

  void YakirGeneration::operator()(const ExpList& e)
  {
    std::vector<Instruction*> ins;
    for (const auto& exp : e.exps_get())
      {
        Instruction* dec_ins = recurse<Exp, Instruction>(exp);

        ins.emplace_back(dec_ins);
      }

    res_ = new InsList(e.location_get(), ins);
  }

  void YakirGeneration::operator()(const NumberExp& e)
  {
    res_ = new Constant(e.location_get(), e.val_get());
  }

  void YakirGeneration::operator()(const ReturnExp& e)
  {
    Val* val = recurse<Exp, Val>(e.return_val_get());

    res_ = new Ret(e.location_get(), val);
  }

  void YakirGeneration::operator()(const StringExp&) {}
  void YakirGeneration::operator()(const TypeName&) {}

} // namespace ast
