#pragma once

#include "block-item.hh"
#include "declaration.hh"
#include "type-name.hh"

#include <vector>

namespace ast
{

  class FunctionDec : public Declaration
  {
  public:
    FunctionDec(const misc::Location& l,
                const std::string& name,
                TypeName* return_type,
                const std::vector<BlockItem*>& body);

    ~FunctionDec() override
    {
      delete return_type_;
      for (auto& bi : body_)
        delete bi;
    }

    virtual void accept(ConstVisitor& v) const override;
    virtual void accept(Visitor& v) override;

    const TypeName& return_type_get() const { return *return_type_; }
    TypeName& return_type_get() { return *return_type_; }

    const std::vector<BlockItem*>& body_get() const { return body_; }

  protected:
    TypeName* return_type_;
    std::vector<BlockItem*> body_;
  };

} // namespace ast
