#pragma once

#include "declaration.hh"

namespace ast
{

  class VarDec : public Declaration
  {
  public:
    VarDec(const misc::Location& loc, const std::string& name, Exp* init);

    ~VarDec() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Exp* init_get() const { return init_; }
    Exp* init_get() { return init_; }

  private:
    Exp* init_;
    ;
  };

} // namespace ast
