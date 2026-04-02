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

  std::ostream& operator<<(std::ostream& os, const Location& l)
  {
    std::string txt = l.file_ + ":" + std::to_string(l.start_line_) + ":"
      + std::to_string(l.start_col_);

    os << bold(txt);
    return os;
  }

  Location Location::operator+(const Location& other) const
  {
    return Location{file_, start_line_, other.end_line_, start_col_,
                    other.end_col_};
  }

  Locable::Locable(const Location& location)
    : location_(location)
  {}
}; // namespace misc
