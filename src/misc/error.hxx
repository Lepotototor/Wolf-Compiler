#pragma once

#include "error.hh"

using namespace misc;

template <typename T> const Error& Error::operator<<(const T& t) const
{
  std::cerr << t;
  return *this;
}

inline unsigned Error::nb_err_get() { return nb_err_; }
inline void Error::nb_err_inc() { nb_err_++; }
inline unsigned Error::nb_warn_get() { return nb_warn_; }
inline void Error::nb_warn_inc() { nb_warn_++; }
