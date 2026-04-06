#include "code-emission.hh"

#include "allocate-stack.hh"
#include "pseudo.hh"
#include "register.hh"
#include "stack.hh"

#define TAB "   "

namespace assembly
{

  void CodeEmit::operator()(const_t<Ret>&)
  {
    ostr_ << TAB << "movq %rbp, %rsp\n";
    ostr_ << TAB << "popq %rbp\n";
    ostr_ << TAB << "ret\n";
  }

  void CodeEmit::operator()(const_t<Mov>& e)
  {
    ostr_ << TAB << "mov " << e.src_get() << ", " << e.dst_get() << "\n";
  }

  void CodeEmit::operator()(const_t<Unary>& e)
  {
    ostr_ << TAB;

    if (e.type_get() == ast::MINUS_U)
      ostr_ << "neg ";
    else if (e.type_get() == ast::TILDE_U)
      ostr_ << "not ";

    ostr_ << e.ope_get() << "\n";
  }

  void CodeEmit::operator()(const_t<AllocateStack>& e)
  {
    ostr_ << TAB << "subq $" << e.size_get() << ", %rsp\n";
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
