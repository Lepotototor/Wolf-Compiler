#include "token.hh"

namespace lexer
{

  token_type Token::type() const { return type_; }

  const std::string& ValueToken::val_get() const { return val_; }

  bool Token::operator==(const Token& t) const
  {
    return this->type_ == t.type_ && this->operator==(tok_repr(t));
  }
  bool Token::operator!=(const Token& t) const { return !this->operator==(t); }

  bool Token::operator==(const std::string& str) const
  {
    return tok_repr(*this) == str;
  }

  bool Token::operator==(const char c) const
  {
    const std::string& repr = tok_repr(*this);
    return repr.size() == 1 && repr[0] == c;
  }

  bool Token::operator!=(const std::string& str) const
  {
    return !this->operator==(str);
  }
  bool Token::operator!=(const char c) const { return !this->operator==(c); }

} // namespace lexer
