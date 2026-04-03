#pragma once

#include <iostream>

#include "immediate.hh"
#include "ins-list.hh"
#include "register.hh"
#include "ret.hh"

namespace assembly
{

  std::ostream& operator<<(std::ostream& os, const AsmNode& e);
  std::ostream& operator<<(std::ostream& os, const AsmNode* e);

} // namespace assembly
