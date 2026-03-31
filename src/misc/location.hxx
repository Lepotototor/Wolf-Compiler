#pragma once

#include "location.hh"

namespace misc
{
  inline const std::string& Location::file_get() const { return file_; }

  inline unsigned Location::start_line_get() const { return start_line_; }
  inline unsigned Location::end_line_get() const { return end_line_; }
  inline unsigned Location::start_col_get() const { return start_col_; }
  inline unsigned Location::end_col_get() const { return end_col_; }

  inline const Location& Locable::location_get() const { return location_; }
} // namespace misc
