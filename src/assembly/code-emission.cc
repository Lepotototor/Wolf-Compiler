#include "code-emission.hh"

namespace assembly
{

  std::ostream& operator<<(std::ostream& os, const AsmNode& e);
  std::ostream& operator<<(std::ostream& os, const AsmNode* e);

} // namespace assembly
