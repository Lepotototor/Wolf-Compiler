#include "pretty-printer.hh"

#include "../ast_nodes/dec-list.hh"
#include "../ast_nodes/exp-list.hh"
#include "../ast_nodes/function-dec.hh"
#include "../ast_nodes/number-exp.hh"
#include "../ast_nodes/return-exp.hh"
#include "../ast_nodes/string-exp.hh"
#include "../ast_nodes/type-name.hh"

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

    ostr_ << e.body_get();

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

  void PrettyPrinter::operator()(const ExpList& e)
  {
    for (const auto& exp : e.exps_get())
      {
        newline();
        ostr_ << exp;
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

    if (e.type_get() == ADD)
      {
        ostr_ << "+";
      }
    else if (e.type_get() == SUB)
      {
        ostr_ << "-";
      }
    else if (e.type_get() == MULT)
      {
        ostr_ << "*";
      }
    else if (e.type_get() == DIV)
      {
        ostr_ << "/";
      }
    else
      {
        ostr_ << "%";
      }

    ostr_ << " " << e.right_get() << ")";
  }

  void PrettyPrinter::operator()(const NumberExp& e) { ostr_ << e.val_get(); }

  void PrettyPrinter::operator()(const StringExp& e) { ostr_ << e.val_get(); }

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
