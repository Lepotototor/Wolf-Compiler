#include "code-emission.hh"

#include "allocate-stack.hh"
#include "comment.hh"
#include "jumpcc.hh"
#include "label.hh"
#include "pseudo.hh"
#include "register.hh"
#include "stack.hh"

#include "../misc/debug.hh"

#define TAB "   "

namespace assembly
{

  void CodeEmit::operator()(const_t<Comment>& e)
  {
    ostr_ << TAB << "# " << e.val_get() << "\n";
  }

  void CodeEmit::operator()(const_t<Ret>&)
  {
    ostr_ << "\n";
    ostr_ << TAB << "movq %rbp, %rsp\n";
    ostr_ << TAB << "popq %rbp\n";
    ostr_ << TAB << "ret\n";
  }

  void CodeEmit::operator()(const_t<Mov>& e)
  {
    ostr_ << TAB << "movl " << e.src_get() << ", " << e.dst_get() << "\n";
  }

  void CodeEmit::operator()(const_t<Unary>& e)
  {
    ostr_ << TAB;

    if (e.type_get() == ast::MINUS_U)
      ostr_ << "negl ";
    else if (e.type_get() == ast::TILDE_U)
      ostr_ << "notl ";

    ostr_ << e.ope_get() << "\n";
  }

  void CodeEmit::operator()(const_t<Binary>& e)
  {
    ostr_ << TAB;

    if (e.type_get() == ast::ADD)
      ostr_ << "addl ";
    else if (e.type_get() == ast::SUB)
      ostr_ << "subl ";
    else if (e.type_get() == ast::MULT)
      ostr_ << "imull ";
    else if (e.type_get() == ast::L_SHIFT)
      ostr_ << "sall ";
    else if (e.type_get() == ast::R_SHIFT)
      ostr_ << "sarl ";
    else if (e.type_get() == ast::B_AND)
      ostr_ << "andl ";
    else if (e.type_get() == ast::L_OR)
      ostr_ << "orl ";
    else if (e.type_get() == ast::XOR)
      ostr_ << "xorl ";
    else
      {
        std::cerr << "Cant generate code for operator: " << e.type_get()
                  << "\n";
      }

    ostr_ << e.left_get() << ", " << e.right_get() << "\n";
  }

  void CodeEmit::operator()(const_t<Cdq>&) { ostr_ << TAB << "cdq\n"; }

  void CodeEmit::operator()(const_t<Idiv>& e)
  {
    ostr_ << TAB << "idivl " << e.ope_get() << "\n";
  }

  void CodeEmit::operator()(const_t<AllocateStack>& e)
  {
    ostr_ << TAB << "subq $" << e.size_get() << ", %rsp\n\n";
  }

  void CodeEmit::operator()(const_t<Cmp>& e)
  {
    ostr_ << TAB << "cmpl " << e.left_get() << ", " << e.right_get() << "\n";
  }

  void CodeEmit::operator()(const_t<Label>& e)
  {
    ostr_ << "\n" << e.name_get() << ":\n";
  }

  void CodeEmit::operator()(const_t<Jump>& e)
  {
    ostr_ << TAB << "jmp " << e.id_get() << "\n";
  }

  void CodeEmit::operator()(const_t<JumpCC>& e)
  {
    ostr_ << TAB << "j";

    if (e.cond_type_get() == ast::EQ)
      ostr_ << "e";
    else if (e.cond_type_get() == ast::NE)
      ostr_ << "ne";
    else if (e.cond_type_get() == ast::LT)
      ostr_ << "l";
    else if (e.cond_type_get() == ast::LE)
      ostr_ << "le";
    else if (e.cond_type_get() == ast::GT)
      ostr_ << "g";
    else if (e.cond_type_get() == ast::GE)
      ostr_ << "ge";
    else
      unreachable();

    ostr_ << " " << e.id_get() << "\n";
  }

  void CodeEmit::operator()(const_t<SetCC>& e)
  {
    ostr_ << TAB << "j";

    if (e.cond_type_get() == ast::EQ)
      ostr_ << "e";
    else if (e.cond_type_get() == ast::NE)
      ostr_ << "ne";
    else if (e.cond_type_get() == ast::LT)
      ostr_ << "l";
    else if (e.cond_type_get() == ast::LE)
      ostr_ << "le";
    else if (e.cond_type_get() == ast::GT)
      ostr_ << "g";
    else if (e.cond_type_get() == ast::GE)
      ostr_ << "ge";
    else
      unreachable();

    ostr_ << " " << e.ope_get() << "\n";
  }

  void CodeEmit::operator()(const_t<FuncDef>& e)
  {
    ostr_ << ".global " << e.name_get() << "\n";
    ostr_ << e.name_get() << ":\n";

    ostr_ << TAB << "pushq %rbp\n";
    ostr_ << TAB << "movq %rsp, %rbp\n";

    for (Instruction* ins : e.instructions_get())
      ostr_ << ins;
  }

  void CodeEmit::operator()(const_t<Register>& e)
  {
    ostr_ << "%" << e.name_get();
  }

  void CodeEmit::operator()(const_t<Immediate>& e)
  {
    ostr_ << "$" << e.val_get();
  }

  void CodeEmit::operator()(const_t<Pseudo>& e) { ostr_ << e.id_get(); }

  void CodeEmit::operator()(const_t<Stack>& e)
  {
    ostr_ << e.index_get() << "(%rbp)";
  }

  void CodeEmit::operator()(const_t<Program>& e)
  {
    ostr_ << ".text\n\n";

    for (const auto& func : e.funcs_get())
      ostr_ << func << "\n";

    //TODO: Disable stack executable
  }
} // namespace assembly

std::ostream& operator<<(std::ostream& os, const assembly::AsmNode& e)
{
  assembly::CodeEmit printer(os);
  e.accept(printer);
  return os;
}

std::ostream& operator<<(std::ostream& os, const assembly::AsmNode* e)
{
  if (e == nullptr)
    return os << "nullptr";
  assembly::CodeEmit printer(os);
  e->accept(printer);
  return os;
}
