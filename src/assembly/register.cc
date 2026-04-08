#include "register.hh"

#include "../visitor/asm_visitor.hh"

namespace assembly
{
  Register::Register(const std::string& name)
    : Operand()
    , name_(name)
  {}

  void Register::accept(ConstVisitor& v) const { v(*this); }
  void Register::accept(Visitor& v) { v(*this); }

  std::map<register_type, std::map<unsigned, std::string>>
    Register::registers_ = {
      {AX, {{1, "al"}, {2, "ax"}, {4, "eax"}, {8, "rax"}}},
      {BX, {{1, "bl"}, {2, "bx"}, {4, "ebx"}, {8, "rbx"}}},
      {CX, {{1, "cl"}, {2, "cx"}, {4, "ecx"}, {8, "rcx"}}},
      {DX, {{1, "dl"}, {2, "dx"}, {4, "edx"}, {8, "rdx"}}},
      {BP, {{1, "bpl"}, {2, "bp"}, {4, "ebp"}, {8, "rbp"}}},
      {SP, {{1, "spl"}, {2, "sp"}, {4, "esp"}, {8, "rsp"}}},
      {SI, {{1, "sil"}, {2, "si"}, {4, "esi"}, {8, "rsi"}}},
      {DI, {{1, "dil"}, {2, "di"}, {4, "edi"}, {8, "rdi"}}},
      {R8, {{1, "r8b"}, {2, "r8w"}, {4, "r8d"}, {8, "r8"}}},
      {R9, {{1, "r9b"}, {2, "r9w"}, {4, "r9d"}, {8, "r9"}}},
      {R10, {{1, "r10b"}, {2, "r10w"}, {4, "r10d"}, {8, "r10"}}},
      {R11, {{1, "r11b"}, {2, "r11w"}, {4, "r11d"}, {8, "r11"}}},
      {R12, {{1, "r12b"}, {2, "r12w"}, {4, "r12d"}, {8, "r12"}}},
      {R13, {{1, "r13b"}, {2, "r13w"}, {4, "r13d"}, {8, "r13"}}},
      {R14, {{1, "r14b"}, {2, "r14w"}, {4, "r14d"}, {8, "r14"}}},
      {R15, {{1, "r15b"}, {2, "r15w"}, {4, "r15d"}, {8, "r15"}}},
  };

} // namespace assembly
