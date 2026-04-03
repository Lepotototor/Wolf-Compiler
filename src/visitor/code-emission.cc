#include "code-emission.hh"

namespace assembly
{
  void CodeEmit::operator()(const_t<InsList>& e)
  {
    for (const auto& ins : e.instructions_get())
      ostr_ << ins;
  }

  void CodeEmit::operator()(const_t<Ret>& e)
  {
    if (e.mov_get())
      {
        ostr_ << e.mov_get();
      }
    ostr_ << "\tret\n";
  }

  void CodeEmit::operator()(const_t<Mov>& e)
  {
    ostr_ << "\tmov" << e.src_get() << ", " << e.dst_get() << "\n";
  }

  void CodeEmit::operator()(const_t<FuncDef>& e)
  {
    ostr_ << ".global " << e.name_get() << "\n";
    ostr_ << e.name_get() << ":\n";

    ostr_ << e.instructions_get();
  }

  void CodeEmit::operator()(const_t<Register>&) { ostr_ << "%eax"; }

  void CodeEmit::operator()(const_t<Immediate>& e)
  {
    ostr_ << "$", e.val_get();
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
