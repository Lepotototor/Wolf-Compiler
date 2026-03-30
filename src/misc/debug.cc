#include "debug.hh"

#include <iostream>

[[noreturn]] void not_implemented_terminate(const char* filename,
                                            const char* filepos,
                                            const char* msg)
{
  std::cerr << "Not implemented code reach at: " << filename << ":" << filepos
            << "\nTODO: " << msg << std::endl;
  abort();
}

[[noreturn]] void unreachable_terminate(const char* filename,
                                        const char* filepos)
{
  std::cerr << "Unreachable code reach at: " << filename << ":" << filepos
            << std::endl;
  abort();
}
