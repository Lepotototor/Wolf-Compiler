#include "pretty-printer.hh"

#include "../ast_nodes/dec-list.hh"
#include "../ast_nodes/function-dec.hh"
#include "../ast_nodes/number-exp.hh"
#include "../ast_nodes/return.hh"
#include "../ast_nodes/string-exp.hh"
#include "../ast_nodes/type-name.hh"
#include "../ast_nodes/var.hh"

#include "../misc/debug.hh"

namespace ast
{
  void PrettyPrinter::newline()
  {
    ostr_ << "\n";
    for (unsigned i = 0; i < indent_; i++)
      {
        ostr_ << "   ";
      }
  }

  void PrettyPrinter::operator()(const FunctionDec& e)
  {
    ostr_ << e.return_type_get() << " " << e.name_get() << "()";

    newline();
    ostr_ << "{";
    indent_++;

    for (const BlockItem* bi : e.body_get())
      {
        newline();
        ostr_ << *bi;
      }

    indent_--;
    newline();
    ostr_ << "}";
    newline();
  }

  void PrettyPrinter::operator()(const DecList& e)
  {
    for (const auto& dec : e.decs_get())
      {
        newline();
        ostr_ << dec;
      }
  }

  void PrettyPrinter::operator()(const UnaryExp& e)
  {
    if (e.type_get() == PLUS_U)
      {
        ostr_ << "+";
      }
    else if (e.type_get() == MINUS_U)
      {
        ostr_ << "-";
      }
    else if (e.type_get() == TILDE_U)
      {
        ostr_ << "~";
      }
    else if (e.type_get() == NEGATE_U)
      {
        ostr_ << "!";
      }

    ostr_ << "(" << e.exp_get() << ")";
  }

  void PrettyPrinter::operator()(const BinaryExp& e)
  {
    ostr_ << "(" << e.left_get() << " ";

    ostr_ << e.type_get();

    ostr_ << " " << e.right_get() << ")";
  }

  void PrettyPrinter::operator()(const NumberExp& e) { ostr_ << e.val_get(); }

  void PrettyPrinter::operator()(const StringExp& e) { ostr_ << e.val_get(); }

  void PrettyPrinter::operator()(const Var& e) { ostr_ << e.identifier_get(); }

  void PrettyPrinter::operator()(const VarDec& e)
  {
    ostr_ << e.name_get();
    if (e.init_get())
      ostr_ << " = " << *e.init_get();
    ostr_ << ";";
  }

  void PrettyPrinter::operator()(const Null&) { ostr_ << ";"; }

  void PrettyPrinter::operator()(const AssignExp& e)
  {
    ostr_ << e.lvalue_get() << " = " << e.rvalue_get();
  }

  void PrettyPrinter::operator()(const ReturnExp& e)
  {
    ostr_ << "return ";
    if (e.return_val_get())
      {
        ostr_ << e.return_val_get();
      }
    ostr_ << ";";
  }

  void PrettyPrinter::operator()(const TypeName& e) { ostr_ << e.name_get(); }
} // namespace ast

std::ostream& operator<<(std::ostream& os, const ast::Ast& e)
{
  ast::PrettyPrinter printer(os);
  e.accept(printer);
  return os;
}

std::ostream& operator<<(std::ostream& os, const ast::Ast* e)
{
  if (e == nullptr)
    return os << "nullptr";
  ast::PrettyPrinter printer(os);
  e->accept(printer);
  return os;
}
