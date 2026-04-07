#pragma once

#include "asm_visitor.hh"

#include "../assembly/binary.hh"
#include "../assembly/cmp.hh"
#include "../assembly/func_def.hh"
#include "../assembly/idiv.hh"
#include "../assembly/immediate.hh"
#include "../assembly/mov.hh"
#include "../assembly/program.hh"
#include "../assembly/ret.hh"
#include "../assembly/setcc.hh"
#include "../assembly/unary.hh"

namespace assembly
{
  template <template <typename> class Const>
  template <class E>
  void GenVisitor<Const>::operator()(E* e)
  {
    if (e)
      e->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<AsmNode>& e)
  {
    e.accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Comment>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Ret>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Mov>& e)
  {
    e.src_get().accept(*this);
    e.dst_get().accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Unary>& e)
  {
    e.ope_get()->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Binary>& e)
  {
    e.left_get()->accept(*this);
    e.right_get()->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Cdq>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Idiv>& e)
  {
    e.ope_get().accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<AllocateStack>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Cmp>& e)
  {
    e.left_get().accept(*this);
    e.right_get().accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Label>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Jump>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<JumpCC>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<SetCC>& e)
  {
    e.ope_get().accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<FuncDef>& e)
  {
    for (Instruction* ins : e.instructions_get())
      ins->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Register>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Immediate>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Pseudo>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Stack>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Program>& e)
  {
    for (auto& func : e.funcs_get())
      func->accept(*this);
  }

} // namespace assembly
