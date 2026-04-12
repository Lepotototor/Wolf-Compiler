#pragma once

#include "ast_visitor.hh"

#include "../ast_nodes/assign.hh"
#include "../ast_nodes/binary-exp.hh"
#include "../ast_nodes/block.hh"
#include "../ast_nodes/break.hh"
#include "../ast_nodes/conditional.hh"
#include "../ast_nodes/continue.hh"
#include "../ast_nodes/dec-list.hh"
#include "../ast_nodes/decrement.hh"
#include "../ast_nodes/do-while.hh"
#include "../ast_nodes/for.hh"
#include "../ast_nodes/function-dec.hh"
#include "../ast_nodes/if.hh"
#include "../ast_nodes/increment.hh"
#include "../ast_nodes/number-exp.hh"
#include "../ast_nodes/return.hh"
#include "../ast_nodes/stmt-exp.hh"
#include "../ast_nodes/string-exp.hh"
#include "../ast_nodes/type-name.hh"
#include "../ast_nodes/unary-exp.hh"
#include "../ast_nodes/var-dec.hh"
#include "../ast_nodes/while.hh"

namespace ast
{
  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<ast::Ast>& e)
  {
    e.accept(*this);
  }

  template <template <typename> class Const>
  template <class E>
  void GenVisitor<Const>::operator()(E* e)
  {
    if (e)
      e->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<FunctionDec>& e)
  {
    e.return_type_get().accept(*this);
    e.body_get().accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<BlockStatement>& e)
  {
    for (auto* bi : e.items_get())
      {
        bi->accept(*this);
      }
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<DecList>& e)
  {
    for (auto& dec : e.decs_get())
      dec->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<NumberExp>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<UnaryExp>& e)
  {
    e.exp_get().accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<BinaryExp>& e)
  {
    e.left_get().accept(*this);
    e.right_get().accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<IncrementExp>& e)
  {
    e.exp_get().accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<DecrementExp>& e)
  {
    e.exp_get().accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<StringExp>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Var>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<AssignExp>& e)
  {
    e.lvalue_get().accept(*this);
    e.rvalue_get().accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<ReturnExp>& e)
  {
    e.return_val_get()->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Null>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<VarDec>& e)
  {
    e.type_get().accept(*this);
    if (e.init_get())
      e.init_get()->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<ExpressionStatement>& e)
  {
    e.exp_get().accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<IfStatement>& e)
  {
    e.cond_get().accept(*this);
    e.then_get().accept(*this);
    if (e.else_get())
      e.else_get()->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<ConditionalExp>& e)
  {
    e.cond_get().accept(*this);
    e.then_get().accept(*this);
    e.else_get().accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<TypeName>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Goto>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Label>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Break>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<Continue>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<While>& e)
  {
    e.cond_get().accept(*this);
    e.body_get().accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<DoWhile>& e)
  {
    e.cond_get().accept(*this);
    e.body_get().accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<For>& e)
  {
    if (e.init_get())
      e.init_get()->accept(*this);
    if (e.cond_get())
      e.cond_get()->accept(*this);
    if (e.post_get())
      e.post_get()->accept(*this);
    e.body_get().accept(*this);
  }

} // namespace ast
