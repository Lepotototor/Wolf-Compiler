#include "assembly-generation.hh"

#include "../assembly/allocate-stack.hh"
#include "../assembly/binary.hh"
#include "../assembly/comment.hh"
#include "../assembly/func_def.hh"
#include "../assembly/immediate.hh"
#include "../assembly/mov.hh"
#include "../assembly/program.hh"
#include "../assembly/register.hh"
#include "../assembly/ret.hh"
#include "../assembly/stack.hh"
#include "../assembly/unary.hh"

#include "../misc/debug.hh"

namespace yakir
{

  void AssemblyGeneration::operator()(const_t<Program>& e)
  {
    std::vector<assembly::FuncDef*> funcs;

    for (const yakir::FuncDef* func : e.funcs_get())
      {
        assembly::FuncDef* f = recurse<yakir::FuncDef, assembly::FuncDef>(func);
        funcs.emplace_back(f);
      }

    res_ = new assembly::Program(funcs);
  }

  void AssemblyGeneration::operator()(const_t<Ret>& e)
  {
    if (e.val_get())
      {
        assembly::Operand* ope = recurse<Val, assembly::Operand>(e.val_get());
        assembly::Register* reg = new assembly::Register("eax");

        curr_func_.emplace_back(new assembly::Mov(ope, reg));
      }

    curr_func_.emplace_back(new assembly::Ret());
  }

  void AssemblyGeneration::operator()(const_t<FuncDef>& e)
  {
    curr_func_.clear();
    stack_size_ = 0;

    for (auto ins : e.instructions_get())
      {
        ins->accept(*this);
      }

    // Use to allocate the stack as many tmp var we need
    // Allocate the stack is done at function start
    if (stack_size_ != 0)
      {
        assembly::AllocateStack* s = new assembly::AllocateStack(stack_size_);
        curr_func_.emplace(curr_func_.begin(), s);
      }

    res_ = new assembly::FuncDef(e.name_get(), curr_func_);
  }

  void AssemblyGeneration::operator()(const_t<Constant>& e)
  {
    res_ = new assembly::Immediate(e.val_get());
  }

  void AssemblyGeneration::operator()(const_t<Var>& e)
  {
    if (var_loc_.contains(e.id_get()))
      {
        res_ = new assembly::Stack(var_loc_[e.id_get()]);
      }
    else
      {
        stack_size_ += 4;
        var_loc_[e.id_get()] = -stack_size_;
        res_ = new assembly::Stack(-stack_size_);
      }
  }

  void AssemblyGeneration::operator()(const_t<Unary>& e)
  {
    using namespace assembly;

    curr_func_.emplace_back(new Comment("Unary operator"));

    Operand* src = recurse<Val, Operand>(e.src_get());
    Operand* dst = recurse<Val, Operand>(e.dst_get());
    Operand* dst_copy = recurse<Val, Operand>(e.dst_get());

    if (dynamic_cast<Stack*>(src) != nullptr
        && dynamic_cast<Stack*>(dst) != nullptr)
      {
        curr_func_.emplace_back(new Mov(src, new Register("r10d")));
        src = new Register("r10d");
      }

    Mov* mov = new Mov(src, dst_copy);
    assembly::Unary* un = new assembly::Unary(e.type_get(), dst);

    curr_func_.emplace_back(mov);
    curr_func_.emplace_back(un);
  }

  void AssemblyGeneration::operator()(const_t<Binary>& e)
  {
    using namespace assembly;

    // TODO if right operand is negative for shift
    // we should throw a warning and return a value
    // It's an undefined behavior

    curr_func_.emplace_back(new Comment("Binary operator"));

    if (e.type_get() == ast::DIV || e.type_get() == ast::MOD)
      {
        notimplmented("Implement Assembly nodes for DIV and MOD");
        return;
      }

    Operand* left = recurse<Val, Operand>(e.left_get());
    Operand* right = recurse<Val, Operand>(e.right_get());

    Operand* dst = recurse<Val, Operand>(e.dst_get());
    Operand* real_dst = dynamic_cast<Stack*>(dst);
    Operand* dst_copy = nullptr;

    // imull can't use a stack adress as output
    if (real_dst != nullptr)
      {
        dst = new Register("r11d");
        dst_copy = new Register("r11d");
      }
    else
      {
        dst_copy = recurse<Val, Operand>(e.dst_get());
      }

    Mov* mov = new Mov(left, dst);
    assembly::Binary* bin = new assembly::Binary(e.type_get(), right, dst_copy);

    curr_func_.emplace_back(mov);
    curr_func_.emplace_back(bin);

    if (real_dst != nullptr)
      {
        // If real dst is a stack addr we should move r11d into the dst
        dst = new Register("r11d");
        Mov* mov = new Mov(dst, real_dst);
        curr_func_.emplace_back(mov);
      }
  }

} // namespace yakir
