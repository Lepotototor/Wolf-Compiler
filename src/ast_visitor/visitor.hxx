#pragma once

#include "visitor.hh"

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
    e.return_type_get()->accept(*this);
    e.body_get()->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<DecList>& e)
  {
    for (auto dec : e.decs_get())
      dec->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<ExpList>& e)
  {
    for (auto exp : e.exps_get())
      exp->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<NumberExp>& e)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<StringExp>& e)
  {}

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<ReturnExp>& e)
  {
    e.return_val_get()->accept(*this);
  }

  template <template <typename> class Const>
  void GenVisitor<Const>::operator()(const_t<TypeName>& e)
  {}

} // namespace ast
