#pragma once

namespace ast
{
  // Each Ast node should have class defnition in ast_nodes
  // Also a default method in visitor.hh and in default_visitor.hxx
  // And implement accept methods to be visit

  class Ast;

  class Declaration;
  class DecList;
  class FunctionDec;

  class Exp;
  class ExpList;
  class NumberExp;
  class UnaryExp;
  class BinaryExp;
  class StringExp;
  class ReturnExp;

  class Type;
  class TypeName;

  /* Forward def of Visiotrs */

  template <template <typename> class Const> class GenVisitor;

  template <typename T> struct const_type;
  template <typename T> struct non_const_type;

  using ConstVisitor = GenVisitor<const_type>;
  using Visitor = GenVisitor<non_const_type>;

} // namespace ast
