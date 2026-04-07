#pragma once

#include "exp.hh"

#include <iostream>

namespace ast
{

  enum binary_type
  {
    ADD,
    SUB,
    MULT,
    DIV,
    MOD,

    L_SHIFT,
    R_SHIFT,
    B_AND,
    B_OR,
    XOR,

    L_AND,
    L_OR,
    EQ,
    NE,
    LT,
    LE,
    GT,
    GE,
  };

  bool is_arit(binary_type type);

  class BinaryExp : public Exp
  {
  public:
    BinaryExp(misc::Location& loc, binary_type type, Exp* left, Exp* right);

    ~BinaryExp() override
    {
      delete left_;
      delete right_;
    }

    // Accept a const visitor
    virtual void accept(ConstVisitor& v) const override;
    // Accept a non-const visitor
    virtual void accept(Visitor& v) override;

    binary_type type_get() const { return type_; }

    const Exp& left_get() const { return *left_; }
    Exp& left_get() { return *left_; }
    const Exp& right_get() const { return *right_; }
    Exp& right_get() { return *right_; }

  private:
    binary_type type_;

    Exp* left_;
    Exp* right_;
  };

} // namespace ast

std::ostream& operator<<(std::ostream& os, enum ast::binary_type type);
