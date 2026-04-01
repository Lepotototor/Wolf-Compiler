#include "location.hh"

#include "format-helper.hh"

namespace misc
{
  Location::Location(const std::string file,
                     unsigned line,
                     unsigned start,
                     unsigned end)
    : file_(file)
    , start_line_(line)
    , end_line_(line)
    , start_col_(start)
    , end_col_(end)
  {}

  Location::Location(const std::string file,
                     unsigned line_start,
                     unsigned line_end,
                     unsigned start,
                     unsigned end)
    : file_(file)
    , start_line_(line_start)
    , end_line_(line_end)
    , start_col_(start)
    , end_col_(end)
  {}

  std::ostream& Location::operator<<(std::ostream& os) const
  {
    std::string txt = file_ + ":" + std::to_string(start_line_) + ":"
      + std::to_string(start_col_);

    os << bold(txt);
    return os;
  }

  Locable::Locable(const Location& location)
    : location_(location)
  {}
}; // namespace misc
