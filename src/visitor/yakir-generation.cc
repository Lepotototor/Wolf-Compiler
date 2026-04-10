#include "yakir-generation.hh"

#include "../ast_nodes/dec-list.hh"
#include "../ast_nodes/function-dec.hh"
#include "../ast_nodes/number-exp.hh"
#include "../ast_nodes/pretty-printer.hh"
#include "../ast_nodes/return.hh"
#include "../ast_nodes/type-name.hh"
#include "../ast_nodes/var.hh"

#include "../yakir/arit-binary.hh"
#include "../yakir/constant.hh"
#include "../yakir/copy.hh"
#include "../yakir/func_def.hh"
#include "../yakir/jump-if-not-zero.hh"
#include "../yakir/jump-if-zero.hh"
#include "../yakir/label.hh"
#include "../yakir/logical-binary.hh"
#include "../yakir/pretty_printer.hh"
#include "../yakir/program.hh"
#include "../yakir/ret.hh"
#include "../yakir/unary.hh"
#include "../yakir/var.hh"

using namespace yakir;

namespace ast
{

  yakir::Var* YakirGeneration::make_tmp_var()
  {
    return new yakir::Var("var" + std::to_string(id_count_++));
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

    e.body_get().accept(*this);

    // In case of no return at end of function
    if (dynamic_cast<yakir::Ret*>(curr_scope_.back()) == nullptr)
      {
        curr_scope_.emplace_back(new Ret(new Constant("67")));
      }

    res_ = new FuncDef(e.name_get(), curr_scope_);
  }

  void YakirGeneration::operator()(const BlockStatement& e)
  {
    for (const BlockItem* bi : e.items_get())
      {
        Instruction* dec_ins = recurse<BlockItem, Instruction>(bi);
        if (dec_ins)
          {
            curr_scope_.emplace_back(dec_ins);
          }
      }
  }

  void YakirGeneration::operator()(const Var& e)
  {
    res_ = new yakir::Var(e.identifier_get());
  }

  void YakirGeneration::operator()(const VarDec& e)
  {
    if (e.init_get() == nullptr)
      {
        res_ = nullptr;
        return;
      }

    yakir::Var* dst = new yakir::Var(e.name_get());
    yakir::Val* src = recurse<Exp, yakir::Val>(*e.init_get());

    res_ = new Copy(src, dst);
  }

  void YakirGeneration::operator()(const AssignExp& e)
  {
    yakir::Val* src = recurse<Exp, Val>(e.rvalue_get());
    yakir::Val* dst = recurse<Exp, Val>(e.lvalue_get());

    res_ = new Copy(src, dst);
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

    yakir::Var* dst = make_tmp_var();

    Unary* ins = new Unary(e.type_get(), src, dst);
    curr_scope_.emplace_back(ins);

    res_ = new yakir::Var(dst->id_get());
  }

  void YakirGeneration::operator()(const BinaryExp& e)
  {
    Val* left = recurse<Exp, Val>(e.left_get());

    yakir::Var* dst = make_tmp_var();

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
          new Copy(new Constant("0"), new yakir::Var(dst->id_get())));
        curr_scope_.emplace_back(end_label);

        res_ = new yakir::Var(dst->id_get());
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

        curr_scope_.emplace_back(new Copy(new Constant("0"), dst));
        Label* end_label = make_tmp_label("end_");
        curr_scope_.emplace_back(new Jump(end_label->name_get()));
        curr_scope_.emplace_back(true_label);
        curr_scope_.emplace_back(
          new Copy(new Constant("1"), new yakir::Var(dst->id_get())));
        curr_scope_.emplace_back(end_label);

        res_ = new yakir::Var(dst->id_get());
        return;
      }

    Val* right = recurse<Exp, Val>(e.right_get());

    if (is_arit(e.type_get()))
      {
        ins = new AritBinary(e.type_get(), left, right, dst);
      }
    else
      {
        std::cout << "Locgical bin\n";
        ins = new LogicalBinary(e.type_get(), left, right, dst);
      }

    curr_scope_.emplace_back(ins);
    res_ = new yakir::Var(dst->id_get());
  }

  void YakirGeneration::operator()(const ReturnExp& e)
  {
    Val* val = recurse<Exp, Val>(e.return_val_get());

    if (val == nullptr)
      std::cout << "RetVal is null\n";

    res_ = new Ret(val);
  }

  void YakirGeneration::operator()(const IfStatement& e)
  {
    Val* cond = recurse<Exp, Val>(e.cond_get());
    Label* end = make_tmp_label("if_end");
    Label* els = e.else_get() ? make_tmp_label("else") : end;

    curr_scope_.emplace_back(new JumpIfZero(els->name_get(), cond));

    Instruction* dec_ins = recurse<BlockItem, Instruction>(e.then_get());
    curr_scope_.emplace_back(dec_ins);

    if (e.else_get())
      {
        curr_scope_.emplace_back(new yakir::Jump(els->name_get()));
        curr_scope_.emplace_back(els);

        dec_ins = recurse<BlockItem, Instruction>(*e.else_get());
        curr_scope_.emplace_back(dec_ins);
      }

    res_ = end;
  }

  void YakirGeneration::operator()(const ConditionalExp& e)
  {
    yakir::Var* res = make_tmp_var();

    Val* cond = recurse<Exp, Val>(e.cond_get());

    Label* cond_false = make_tmp_label("cond_false");
    Label* end = make_tmp_label("cond_end");

    curr_scope_.emplace_back(new JumpIfZero(cond_false->name_get(), cond));

    Val* then = recurse<Exp, Val>(e.then_get());
    curr_scope_.emplace_back(new Copy(then, new yakir::Var(res->id_get())));
    curr_scope_.emplace_back(new Jump(end->name_get()));

    curr_scope_.emplace_back(cond_false);
    Val* els = recurse<Exp, Val>(e.else_get());
    curr_scope_.emplace_back(new Copy(els, new yakir::Var(res->id_get())));

    curr_scope_.emplace_back(end);

    res_ = res;
  }

  void YakirGeneration::operator()(const StringExp&) {}
  void YakirGeneration::operator()(const TypeName&) {}

} // namespace ast
