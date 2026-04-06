#pragma once

#include "ast_visitor.hh"

#include "../ast_nodes/binary-exp.hh"
#include "../ast_nodes/dec-list.hh"
#include "../ast_nodes/exp-list.hh"
#include "../ast_nodes/function-dec.hh"
#include "../ast_nodes/number-exp.hh"
#include "../ast_nodes/return-exp.hh"
#include "../ast_nodes/string-exp.hh"
#include "../ast_nodes/type-name.hh"
#include "../ast_nodes/unary-exp.hh"

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
    e.body_get()->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<DecList>& e)
  {
    for (auto& dec : e.decs_get())
      dec->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<ExpList>& e)
  {
    for (auto& exp : e.exps_get())
      exp->accept(*this);
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
  void GenVisitor<Const>::operator()(const_t<StringExp>&)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<ReturnExp>& e)
  {
    e.return_val_get()->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<TypeName>&)
  {}

} // namespace ast
