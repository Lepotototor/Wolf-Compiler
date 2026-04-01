#pragma once

#include <queue>

#include "../driver/wolf-driver.hh"
#include "scan-wolf.hh"
#include "token.hh"

namespace lexer
{
  std::queue<Token> lex(const std::string& file, driver::WolfDriver& wd);
}
