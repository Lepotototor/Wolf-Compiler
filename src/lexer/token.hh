#pragma once

#include "../misc/location.hh"

namespace lexer
{
  enum token_type
  {
    END_OF_FILE = 0,
    UNKNOW
  };

  class Token : public misc::Locable
  {
  public:
    token_type type() const;

  private:
    token_type type_;
  };

} // namespace lexer
