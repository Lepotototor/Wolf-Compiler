#pragma once

#include "declaration.hh"
#include "exp.hh"
#include "type-name.hh"

namespace ast
{

  class FunctionDec : public Declaration
  {
  public:
    FunctionDec(const misc::Location& l,
                const std::string& name,
                TypeName* return_type,
                Exp* body)
      : Declaration(l, name)
      , return_type_(return_type)
      , body_(body)
    {}

    ~FunctionDec() override
    {
      delete return_type_;
      delete body_;
    }

    virtual void accept(ConstVisitor& v) const override { v(*this); }
    virtual void accept(Visitor& v) override { v(*this); }

    const TypeName& return_type_get() const { return *return_type_; }
    TypeName& return_type_get() { return *return_type_; }

    const Exp* body_get() const { return body_; }
    Exp* body_get() { return body_; }

  protected:
    TypeName* return_type_;
    Exp* body_;
  };

} // namespace ast
