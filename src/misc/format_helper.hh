#pragma once

#include <string>

namespace misc
{
  std::string bold(const std::string& s);

  std::string warn(bool compile_error = true);
  std::string err();
} // namespace misc
