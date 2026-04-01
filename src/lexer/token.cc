#include "token.hh"

namespace lexer
{

  token_type Token::type() const { return type_; }

  const std::string& ValueToken::val_get() const { return val_; }

  bool Token::operator==(const std::string& str) const
  {
    return tok_repr(*this) == str;
  }

  bool Token::operator==(const char c) const
  {
    const std::string& repr = tok_repr(*this);
    return repr.size() == 1 && repr[0] == c;
  }

  bool ValueToken::operator==(const std::string& str) const
  {
    return this->val_ == str;
  }

  bool ValueToken::operator==(const char c) const
  {
    return this->val_.size() == 1 && this->val_[0] == c;
  }

} // namespace lexer
