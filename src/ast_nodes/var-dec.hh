#pragma once

#include "declaration.hh"
#include "for-init.hh"
#include "type-name.hh"

namespace ast
{

  class VarDec
    : public Declaration
    , public ForInit
  {
  public:
    VarDec(const misc::Location& loc,
           const std::string& name,
           TypeName* type,
           Exp* init);

    ~VarDec() override;

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const Exp* init_get() const { return init_; }
    Exp* init_get() { return init_; }

    const TypeName& type_get() const { return *type_; }
    TypeName& type_get() { return *type_; }

  private:
    TypeName* type_;

    Exp* init_;
    ;
  };

} // namespace ast
