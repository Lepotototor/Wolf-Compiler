#pragma once

#include <iostream>

namespace misc
{
  enum error_type
  {
    no_error = 0,
    failure = 1,
    scan = 2,
    parse = 3,
    bind = 4,
    type = 5
  };

  class Error
  {
  public:
    Error();

    [[noreturn]] void exit();
    void exit_on_error();

    // Use to set status
    Error& operator<<(error_type e);

    // Use to print elements to std::cerr
    template <typename T> const Error& operator<<(const T& t) const;

    static Error& warn(Error& e, bool compile_warn = true);
    static Error& err(Error& e);

    //Use to handle std::flush, std::endl, ..
    const Error& operator<<(std::ostream& (*f)(std::ostream&)) const;
    // Use to handle warn and err
    const Error& operator<<(Error& (*f)(Error&)) const;

    // Use to stor statistics about errors and warnings
    static unsigned nb_err_get();
    static void nb_err_inc();
    static unsigned nb_warn_get();
    static void nb_warn_inc();

  private:
    bool is_a_tty_;

    // To know if warning appear during commpilation
    bool compile_warn_ = false;

    error_type status_ = error_type::failure;

    static unsigned nb_err_;
    static unsigned nb_warn_;
  };

} // namespace misc
