#include "format_helper.hh"
#include "error.hh"

#include <unistd.h>

namespace misc
{
  bool tty_ = false;
  bool tty_set = false;

  bool is_a_tty()
  {
    if (!tty_set)
      {
        if (isatty(STDOUT_FILENO))
          tty_ = true;
        tty_set = true;
      }

    return tty_;
  }

  std::string color(int r, int g, int b)
  {
    std::string seq = "[38;2;";
    seq += std::to_string(r) + ";";
    seq += std::to_string(g) + ";";
    seq += std::to_string(b) + ";";
    seq += "m";

    return "\x1b" + seq;
  }

  std::string apply_color(const std::string& s, const std::string color)
  {
    return color + s + "\033[0m";
  }

  std::string bold(const std::string& s) { return "\033[1m" + s + "\033[0m"; }

  std::string warn(bool compile_error)
  {
    if (compile_error)
      Error::nb_warn_inc();

    std::string txt = "Warning: ";
    if (is_a_tty())
      {
        return apply_color(bold(txt), YELLOW);
      }
    else
      return txt;
  }

  std::string err()
  {
    Error::nb_err_inc();

    std::string txt = "Error: ";
    if (is_a_tty())
      return apply_color(bold(txt), RED);
    else
      return txt;
  }
} // namespace misc
