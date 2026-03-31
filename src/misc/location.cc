#include "location.hh"

#include "format_helper.hh"

namespace misc
{

  std::ostream& Location::operator<<(std::ostream& os) const
  {
    std::string txt = file_ + ":" + std::to_string(start_line_) + ":"
      + std::to_string(start_col_);

    os << bold(txt);
    return os;
  }

  Locatable::Locatable(const Location& location)
    : location_(location)
  {}
}; // namespace misc
