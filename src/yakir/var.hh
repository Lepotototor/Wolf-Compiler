#pragma once

#include "val.hh"

#include <string>

namespace yakir
{

  class Var : public Val
  {
  public:
    Var(const std::string& val);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const std::string& id_get() const { return id_; }

  private:
    std::string id_;
  };

} // namespace yakir
