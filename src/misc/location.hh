#pragma once

#include <iostream>
#include <string>

namespace misc
{

  class Location
  {
  public:
    Location(const std::string file,
             unsigned line,
             unsigned start,
             unsigned end);

    Location(const std::string file,
             unsigned line_start,
             unsigned line_end,
             unsigned start,
             unsigned end);

    friend std::ostream& operator<<(std::ostream& os, const Location& l);

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

  protected:
    Location location_;
  };
} // namespace misc

#include "location.hxx"
