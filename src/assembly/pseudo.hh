#pragma once

#include "operand.hh"

#include <string>

namespace assembly
{

  class Pseudo : public Operand
  {
  public:
    Pseudo(const std::string& id);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    const std::string& id_get() const { return id_; }
    void set_id(const std::string& id) { id_ = id; }

  private:
    std::string id_;
  };

} // namespace assembly
