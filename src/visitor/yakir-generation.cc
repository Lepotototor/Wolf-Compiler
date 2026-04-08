#include "yakir-generation.hh"

#include "../ast_nodes/dec-list.hh"
#include "../ast_nodes/exp-list.hh"
#include "../ast_nodes/function-dec.hh"
#include "../ast_nodes/number-exp.hh"
#include "../ast_nodes/return-exp.hh"
#include "../ast_nodes/type-name.hh"

#include "../yakir/arit-binary.hh"
#include "../yakir/constant.hh"
#include "../yakir/copy.hh"
#include "../yakir/func_def.hh"
#include "../yakir/jump-if-not-zero.hh"
#include "../yakir/jump-if-zero.hh"
#include "../yakir/label.hh"
#include "../yakir/logical-binary.hh"
#include "../yakir/program.hh"
#include "../yakir/ret.hh"
#include "../yakir/unary.hh"
#include "../yakir/var.hh"

using namespace yakir;

namespace ast
{

  Var* YakirGeneration::make_tmp_var()
  {
    return new Var("var" + std::to_string(id_count_++));
  }

  yakir::Label* YakirGeneration::make_tmp_label(std::string base)
  {
    return new Label(base + std::to_string(lbl_count_++));
  }

  void YakirGeneration::operator()(const DecList& e)
  {
    std::vector<FuncDef*> funcs;

    for (const auto& dec : e.decs_get())
      {
        FuncDef* func = recurse<Declaration, FuncDef>(dec);
        funcs.emplace_back(func);
      }

    res_ = new Program(funcs);
  }

  void YakirGeneration::operator()(const FunctionDec& e)
  {
    curr_scope_.clear();
    e.body_get()->accept(*this);
    res_ = new FuncDef(e.name_get(), curr_scope_);
  }

  void YakirGeneration::operator()(const ExpList& e)
  {
    for (const auto& exp : e.exps_get())
      {
        Instruction* dec_ins = recurse<Exp, Instruction>(exp);

        curr_scope_.emplace_back(dec_ins);
      }

    // res_ = new InsList(ins);
  }

  void YakirGeneration::operator()(const NumberExp& e)
  {
    res_ = new Constant(e.val_get());
  }

  void YakirGeneration::operator()(const UnaryExp& e)
  {
    Val* src = recurse<Exp, Val>(e.exp_get());

    if (e.type_get() == PLUS_U)
      {
        res_ = src;
        return;
      }

    Var* dst = make_tmp_var();

    Unary* ins = new Unary(e.type_get(), src, dst);
    curr_scope_.emplace_back(ins);

    res_ = new Var(dst->id_get());
  }

  void YakirGeneration::operator()(const BinaryExp& e)
  {
    Val* left = recurse<Exp, Val>(e.left_get());

    Var* dst = make_tmp_var();

    Binary* ins = nullptr;
    if (e.type_get() == L_AND)
      {
        Label* false_label = make_tmp_label("and_false_");
        curr_scope_.emplace_back(new JumpIfZero(false_label->name_get(), left));

        Val* right = recurse<Exp, Val>(e.right_get());
        curr_scope_.emplace_back(
          new JumpIfZero(false_label->name_get(), right));

        curr_scope_.emplace_back(new Copy(new Constant("1"), dst));
        Label* end_label = make_tmp_label("end_");
        curr_scope_.emplace_back(new Jump(end_label->name_get()));
        curr_scope_.emplace_back(false_label);
        curr_scope_.emplace_back(
          new Copy(new Constant("0"), new Var(dst->id_get())));
        curr_scope_.emplace_back(end_label);

        res_ = new Var(dst->id_get());
        return;
      }
    else if (e.type_get() == L_OR)
      {
        Label* true_label = make_tmp_label("or_true_");
        curr_scope_.emplace_back(
          new JumpIfNotZero(true_label->name_get(), left));

        Val* right = recurse<Exp, Val>(e.right_get());
        curr_scope_.emplace_back(
          new JumpIfNotZero(true_label->name_get(), right));

        curr_scope_.emplace_back(new Copy(new Constant("1"), dst));
        Label* end_label = make_tmp_label("end_");
        curr_scope_.emplace_back(new Jump(end_label->name_get()));
        curr_scope_.emplace_back(true_label);
        curr_scope_.emplace_back(
          new Copy(new Constant("0"), new Var(dst->id_get())));
        curr_scope_.emplace_back(end_label);

        res_ = new Var(dst->id_get());
        return;
      }

    Val* right = recurse<Exp, Val>(e.right_get());

    if (is_arit(e.type_get()))
      {
        ins = new AritBinary(e.type_get(), left, right, dst);
      }
    else
      {
        ins = new LogicalBinary(e.type_get(), left, right, dst);
      }

    curr_scope_.emplace_back(ins);
    res_ = new Var(dst->id_get());
  }

  void YakirGeneration::operator()(const ReturnExp& e)
  {
    Val* val = recurse<Exp, Val>(e.return_val_get());

    if (val == nullptr)
      std::cout << "RetVal is null\n";

    res_ = new Ret(val);
  }

  void YakirGeneration::operator()(const StringExp&) {}
  void YakirGeneration::operator()(const TypeName&) {}

} // namespace ast
