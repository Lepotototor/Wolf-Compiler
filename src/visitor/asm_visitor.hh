#pragma once

#include "../assembly/all_nodes.hh"

namespace assembly
{
  template <template <typename> class Const> class GenVisitor
  {
  public:
    template <typename Type> using const_t = typename Const<Type>::type;

    virtual ~GenVisitor() = default;

    // Use to visit node by pointer
    template <class E> void operator()(E* e);

    /*      Assembly Visitors       */
    virtual void operator()(const_t<AsmNode>& e);

    virtual void operator()(const_t<Ret>& e);
    virtual void operator()(const_t<Mov>& e);
    virtual void operator()(const_t<Unary>& e);
    virtual void operator()(const_t<FuncDef>& e);
    virtual void operator()(const_t<Register>& e);
    virtual void operator()(const_t<Immediate>& e);
    virtual void operator()(const_t<Pseudo>& e);
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

} // namespace assembly

#include "asm_visitor.hxx"
