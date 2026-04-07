#include "../visitor/ast_visitor.hh"

#include "binary-exp.hh"

#include "../misc/debug.hh"

namespace ast
{

  BinaryExp::BinaryExp(misc::Location& loc,
                       binary_type type,
                       Exp* left,
                       Exp* right)
    : Exp(loc)
    , type_(type)
    , left_(left)
    , right_(right)
  {}

  void BinaryExp::accept(ConstVisitor& v) const { v(*this); }
  void BinaryExp::accept(Visitor& v) { v(*this); }

  bool is_arit(binary_type type)
  {
    return type == ADD || type == SUB || type == MULT || type == DIV
      || type == MOD || type == L_SHIFT || type == R_SHIFT || type == B_AND
      || type == B_OR || type == XOR;
  }

} // namespace ast

std::ostream& operator<<(std::ostream& os, enum ast::binary_type type)
{
  if (type == ast::ADD)
    os << "+";
  else if (type == ast::SUB)
    os << "-";
  else if (type == ast::MULT)
    os << "*";
  else if (type == ast::DIV)
    os << "/";
  else if (type == ast::MOD)
    os << "%";
  else if (type == ast::L_SHIFT)
    os << "<<";
  else if (type == ast::R_SHIFT)
    os << ">>";
  else if (type == ast::B_AND)
    os << "&";
  else if (type == ast::B_OR)
    os << "|";
  else if (type == ast::XOR)
    os << "^";
  else if (type == ast::L_AND)
    os << "&&";
  else if (type == ast::L_OR)
    os << "||";
  else if (type == ast::EQ)
    os << "==";
  else if (type == ast::NE)
    os << "!=";
  else if (type == ast::LT)
    os << "<";
  else if (type == ast::LE)
    os << "<=";
  else if (type == ast::GT)
    os << ">";
  else if (type == ast::GE)
    os << ">=";
  else
    unreachable();

  return os;
}
