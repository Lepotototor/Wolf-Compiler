#include "format_helper.hh"
#include "error.hh"

namespace misc
{
  std::string bold(const std::string& s) { return "\033[1m" + s + "\033[0m"; }

  std::string warn(bool compile_error)
  {
    if (compile_error)
      Error::nb_warn_inc();

    return bold("Warning: ");
  }

  std::string err()
  {
    Error::nb_err_inc();

    return bold("Error: ");
  }
} // namespace misc
