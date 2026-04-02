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
  class StringExp;
  class ReturnExp;

  class Type;
  class TypeName;

} // namespace ast
