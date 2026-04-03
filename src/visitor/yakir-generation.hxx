#pragma once

#include "yakir-generation.hh"

namespace ast
{
  template <typename AST, typename YAKIR>
  YAKIR* YakirGeneration::recurse(const AST& t)
  {
    t.accept(*this);
    YAKIR* res = dynamic_cast<YAKIR*>(res_);
    return res;
  }

  template <typename AST, typename YAKIR>
  YAKIR* YakirGeneration::recurse(const AST* t)
  {
    if (t == nullptr)
      return nullptr;

    t->accept(*this);
    YAKIR* res = dynamic_cast<YAKIR*>(res_);
    return res;
  }
} // namespace ast
