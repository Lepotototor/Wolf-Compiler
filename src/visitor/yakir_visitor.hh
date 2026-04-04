#pragma once

#include "../yakir/all_nodes.hh"

namespace yakir
{
  template <template <typename> class Const> class GenVisitor
  {
  public:
    template <typename Type> using const_t = typename Const<Type>::type;

    virtual ~GenVisitor() = default;

    // Use to visit node by pointer
    template <class E> void operator()(E* e);

    /*      Yakir Visitors       */
    virtual void operator()(const_t<YakirNode>& e);

    virtual void operator()(const_t<InsList>& e);
    virtual void operator()(const_t<Ret>& e);
    virtual void operator()(const_t<FuncDef>& e);
    virtual void operator()(const_t<Constant>& e);
    virtual void operator()(const_t<Var>& e);
    virtual void operator()(const_t<Unary>& e);
    virtual void operator()(const_t<Program>& e);
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

} // namespace yakir

#include "yakir_visitor.hxx"
