#pragma once

#include "assembly-generation.hh"

namespace yakir
{
  template <typename YAKIR, typename ASM>
  ASM* AssemblyGeneration::recurse(const YAKIR& t)
  {
    t.accept(*this);
    return dynamic_cast<ASM*>(res_);
  }

  template <typename YAKIR, typename ASM>
  ASM* AssemblyGeneration::recurse(const YAKIR* t)
  {
    if (t == nullptr)
      return nullptr;

    t->accept(*this);
    return dynamic_cast<ASM*>(res_);
  }
} // namespace yakir
