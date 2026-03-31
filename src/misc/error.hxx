#pragma once

#include "error.hh"

using namespace misc;

template <typename T> Error& Error::operator<<(const T& t)
{
  std::cerr << t;
  return *this;
}
