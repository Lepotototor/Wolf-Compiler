#pragma once

#include "../visitor/ast_visitor.hh"

#include <string>

namespace ast
{

  class Renamer : public Visitor
  {
  public:
    Renamer() {}

    virtual void operator()(Var& e) override;
    virtual void operator()(VarDec& e) override;

  private:
    unsigned count_ = 0;
  };

} // namespace ast
