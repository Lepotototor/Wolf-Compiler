#pragma once

#include "yakir_visitor.hh"

#include "../yakir/arit-binary.hh"
#include "../yakir/constant.hh"
#include "../yakir/func_def.hh"
#include "../yakir/logical-binary.hh"
#include "../yakir/program.hh"
#include "../yakir/ret.hh"
#include "../yakir/unary.hh"
#include "../yakir/var.hh"

namespace yakir
{
  template <template <typename> class Const>
  template <class E>
  void GenVisitor<Const>::operator()(E* e)
  {
    if (e)
      e->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<YakirNode>& e)
  {
    e.accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Ret>& e)
  {
    if (e.val_get())
      e.val_get()->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<FuncDef>& e)
  {
    for (Instruction* ins : e.instructions_get())
      ins->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Constant>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Var>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Unary>& e)
  {
    e.src_get().accept(*this);
    e.dst_get().accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<AritBinary>& e)
  {
    e.left_get().accept(*this);
    e.right_get().accept(*this);
    e.dst_get().accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<LogicalBinary>& e)
  {
    e.left_get().accept(*this);
    e.right_get().accept(*this);
    e.dst_get().accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Program>& e)
  {
    for (auto& func : e.funcs_get())
      func->accept(*this);
  }

} // namespace yakir
