#pragma once

#include "assembly-generation.hh"

namespace ast
{
  template <typename AST, typename ASM>
  ASM* AsmGeneration::recurse(const AST& t)
  {
    t.accept(*this);
    ASM* res = dynamic_cast<ASM*>(res_);
    return res;
  }

  template <typename AST, typename ASM>
  ASM* AsmGeneration::recurse(const AST* t)
  {
    if (t == nullptr)
      return nullptr;

    t->accept(*this);
    ASM* res = dynamic_cast<ASM*>(res_);
    return res;
  }
} // namespace ast
