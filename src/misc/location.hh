#pragma once

#include <iostream>
#include <string>

namespace misc
{

  class Location
  {
    Location(const std::string file);

    std::ostream& operator<<(std::ostream& os) const;

    const std::string& file_get() const;

    unsigned start_line_get() const;
    unsigned end_line_get() const;
    unsigned start_col_get() const;
    unsigned end_col_get() const;

  private:
    std::string file_;

    unsigned start_line_;
    unsigned end_line_;

    unsigned start_col_;
    unsigned end_col_;
  };

  class Locable
  {
  public:
    Locable(const Location&);
    const Location& location_get() const;

  private:
    Location location_;
  };
} // namespace misc

#include "location.hxx"
