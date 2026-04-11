#pragma once

namespace assembly
{
  // Each Assembly node should have class defnition in assembly
  // Also a default method in visitor.hh and in default_visitor.hxx
  // And implement accept methods to be visit

  class AsmNode;

  class Comment;

  class Instruction;
  class Ret;
  class Mov;
  class Unary;
  class Binary;
  class Inc;
  class Dec;
  class AllocateStack;
  class Idiv;
  class Cdq;
  class Cmp;
  class Jump;
  class JumpCC;
  class SetCC;
  class Label;

  class FuncDef;
  class Operand;
  class Register;
  class Immediate;
  class Pseudo;
  class Stack;

  class Program;

  /* Forward def of Visiotrs */

  template <template <typename> class Const> class GenVisitor;

  template <typename T> struct const_type;
  template <typename T> struct non_const_type;

  using ConstVisitor = GenVisitor<const_type>;
  using Visitor = GenVisitor<non_const_type>;

} // namespace assembly
