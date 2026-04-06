#include "yakir-generation.hh"

#include "../ast_nodes/dec-list.hh"
#include "../ast_nodes/exp-list.hh"
#include "../ast_nodes/function-dec.hh"
#include "../ast_nodes/number-exp.hh"
#include "../ast_nodes/return-exp.hh"
#include "../ast_nodes/type-name.hh"

#include "../yakir/binary.hh"
#include "../yakir/constant.hh"
#include "../yakir/func_def.hh"
#include "../yakir/program.hh"
#include "../yakir/ret.hh"
#include "../yakir/unary.hh"
#include "../yakir/var.hh"

using namespace yakir;

namespace ast
{

  Var* YakirGeneration::make_tmp_var(const misc::Location& loc)
  {
    return new Var(loc, "var" + std::to_string(id_count_++));
  }

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
    curr_scope_.clear();
    e.body_get()->accept(*this);
    res_ = new FuncDef(e.location_get(), e.name_get(), curr_scope_);
  }

  void YakirGeneration::operator()(const ExpList& e)
  {
    for (const auto& exp : e.exps_get())
      {
        Instruction* dec_ins = recurse<Exp, Instruction>(exp);

        curr_scope_.emplace_back(dec_ins);
      }

    // res_ = new InsList(e.location_get(), ins);
  }

  void YakirGeneration::operator()(const NumberExp& e)
  {
    res_ = new Constant(e.location_get(), e.val_get());
  }

  void YakirGeneration::operator()(const UnaryExp& e)
  {
    Val* src = recurse<Exp, Val>(e.exp_get());

    if (e.type_get() == PLUS_U)
      {
        res_ = src;
        return;
      }

    Var* dst = make_tmp_var(e.location_get());

    Unary* ins = new Unary(e.location_get(), e.type_get(), src, dst);
    curr_scope_.emplace_back(ins);

    res_ = new Var(dst->location_get(), dst->id_get());
  }

  void YakirGeneration::operator()(const BinaryExp& e)
  {
    Val* left = recurse<Exp, Val>(e.left_get());
    Val* right = recurse<Exp, Val>(e.right_get());

    Var* dst = make_tmp_var(e.location_get());

    Binary* ins = new Binary(e.location_get(), e.type_get(), left, right, dst);
    curr_scope_.emplace_back(ins);

    res_ = new Var(dst->location_get(), dst->id_get());
  }

  void YakirGeneration::operator()(const ReturnExp& e)
  {
    Val* val = recurse<Exp, Val>(e.return_val_get());

    if (val == nullptr)
      std::cout << "RetVal is null\n";

    res_ = new Ret(e.location_get(), val);
  }

  void YakirGeneration::operator()(const StringExp&) {}
  void YakirGeneration::operator()(const TypeName&) {}

} // namespace ast
