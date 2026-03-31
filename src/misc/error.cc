#include "error.hh"

#include <unistd.h>

using namespace misc;

Error::Error() { is_a_tty_ = isatty(STDIN_FILENO); }

[[noreturn]] void Error::exit()
{
  std::cerr << std::flush;
  throw *this;
}

void Error::exit_on_error()
{
  if (status_ != error_type::no_error)
    exit();
}

Error& Error::operator<<(error_type e)
{
  status_ = e < status_ ? e : status_;
  return *this;
}

const Error& Error::operator<<(std::ostream& (*f)(std::ostream&)) const
{
  std::cerr << f;
  return *this;
}
