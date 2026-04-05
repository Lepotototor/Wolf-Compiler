#pragma once

#include "operand.hh"

namespace assembly
{

  class Stack : public Operand
  {
  public:
    Stack(const misc::Location& loc, int index);

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    int index_get() const { return index_; }
    void index_get(int index) { index_ = index; }

  private:
    int index_;
  };

} // namespace assembly
