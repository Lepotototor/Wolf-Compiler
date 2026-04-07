#include "pretty_printer.hh"

#define TAB "   "

namespace yakir
{
  void PrettyPrinter::operator()(const_t<Ret>& e)
  {
    ostr_ << TAB << "ret ";
    if (e.val_get())
      {
        ostr_ << e.val_get() << "\n";
      }
  }

  void PrettyPrinter::operator()(const_t<Unary>& e)
  {
    ostr_ << TAB << e.dst_get() << " = ";

    if (e.type_get() == ast::unary_type::MINUS_U)
      ostr_ << "-";
    else if (e.type_get() == ast::unary_type::TILDE_U)
      ostr_ << "~";
    else
      ostr_ << "!";

    ostr_ << " " << e.src_get() << "\n";
  }

  void PrettyPrinter::operator()(const_t<Binary>& e)
  {
    ostr_ << TAB << e.dst_get() << " = " << e.left_get() << " ";

    if (e.type_get() == ast::ADD)
      ostr_ << "+";
    else if (e.type_get() == ast::SUB)
      ostr_ << "-";
    else if (e.type_get() == ast::MULT)
      ostr_ << "*";
    else if (e.type_get() == ast::DIV)
      ostr_ << "/";
    else if (e.type_get() == ast::MOD)
      ostr_ << "%";
    else if (e.type_get() == ast::L_SHIFT)
      ostr_ << "<<";
    else if (e.type_get() == ast::R_SHIFT)
      ostr_ << ">>";
    else if (e.type_get() == ast::AND)
      ostr_ << "&";
    else if (e.type_get() == ast::OR)
      ostr_ << "|";
    else if (e.type_get() == ast::XOR)
      ostr_ << "^";

    ostr_ << " " << e.right_get() << "\n";
  }

  void PrettyPrinter::operator()(const_t<FuncDef>& e)
  {
    ostr_ << e.name_get() << ":\n";

    for (const Instruction* ins : e.instructions_get())
      ostr_ << ins;
  }

  void PrettyPrinter::operator()(const_t<Constant>& e) { ostr_ << e.val_get(); }

  void PrettyPrinter::operator()(const_t<Var>& e) { ostr_ << e.id_get(); }

  void PrettyPrinter::operator()(const_t<Program>& e)
  {
    for (const auto& func : e.funcs_get())
      ostr_ << func << "\n";
  }
} // namespace yakir

std::ostream& operator<<(std::ostream& os, const yakir::YakirNode& e)
{
  yakir::PrettyPrinter printer(os);
  e.accept(printer);
  return os;
}

std::ostream& operator<<(std::ostream& os, const yakir::YakirNode* e)
{
  if (e == nullptr)
    return os << "nullptr";
  yakir::PrettyPrinter printer(os);
  e->accept(printer);
  return os;
}
