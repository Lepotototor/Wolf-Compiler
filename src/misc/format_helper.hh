#pragma once

#include <string>

#define BLUE color(115, 113, 252)
#define YELLOW color(247, 221, 114)
#define RED color(239, 71, 111)

namespace misc
{
  std::string apply_color(const std::string& color, const std::string s);
  std::string bold(const std::string& s);

  std::string warn(bool compile_error = true);
  std::string err();
} // namespace misc
