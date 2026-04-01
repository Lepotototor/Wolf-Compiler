#pragma once

#include "../ast_nodes/all_nodes.hh"

namespace ast
{
  template <template <typename> class Const> class GenVisitor
  {
  public:
    template <typename Type> using const_t = typename Const<Type>::type;

    virtual ~GenVisitor() = default;

    // Use to visit node by pointer
    template <class E> void operator()(E* e);

    virtual void operator()(const_t<Ast>& e);

    virtual void operator()(const_t<FunctionDec>& e);
    virtual void operator()(const_t<ExpList>& e);
    virtual void operator()(const_t<NumberExp>& e);
    virtual void operator()(const_t<StringExp>& e);
    virtual void operator()(const_t<ReturnExp>& e);
    virtual void operator()(const_t<TypeName>& e);
  };

  template <typename T> struct const_type
  {
    using type = const T;
  };

  template <typename T> struct non_const_type
  {
    using type = T;
  };

  using ConstVisitor = GenVisitor<const_type>;

  using Visitor = GenVisitor<non_const_type>;

} // namespace ast

#include "visitor.hxx"
