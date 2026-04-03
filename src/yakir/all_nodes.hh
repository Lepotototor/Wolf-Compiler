#pragma once

namespace yakir
{
  // Each Yakir node should have class defnition in yakir
  // Also a default method in visitor.hh and in default_visitor.hxx
  // And implement accept methods to be visit

  class YakirNode;

  class Instruction;
  class InsList;
  class Ret;
  class Mov;

  class FuncDef;
  class Operand;
  class Register;
  class Immediate;

  class Program;

  /* Forward def of Visiotrs */

  template <template <typename> class Const> class GenVisitor;

  template <typename T> struct const_type;
  template <typename T> struct non_const_type;

  using ConstVisitor = GenVisitor<const_type>;
  using Visitor = GenVisitor<non_const_type>;

} // namespace yakir
