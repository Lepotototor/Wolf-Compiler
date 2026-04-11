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

    /*      AST Visitors            */
    virtual void operator()(const_t<Ast>& e);

    virtual void operator()(const_t<FunctionDec>& e);
    virtual void operator()(const_t<BlockStatement>& e);
    virtual void operator()(const_t<DecList>& e);
    virtual void operator()(const_t<VarDec>& e);
    virtual void operator()(const_t<ExpressionStatement>& e);
    virtual void operator()(const_t<Null>& e);
    virtual void operator()(const_t<NumberExp>& e);
    virtual void operator()(const_t<UnaryExp>& e);
    virtual void operator()(const_t<BinaryExp>& e);
    virtual void operator()(const_t<IncrementExp>& e);
    virtual void operator()(const_t<DecrementExp>& e);
    virtual void operator()(const_t<StringExp>& e);
    virtual void operator()(const_t<Var>& e);
    virtual void operator()(const_t<AssignExp>& e);
    virtual void operator()(const_t<ReturnExp>& e);
    virtual void operator()(const_t<IfStatement>& e);
    virtual void operator()(const_t<ConditionalExp>& e);
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

#include "ast_visitor.hxx"
