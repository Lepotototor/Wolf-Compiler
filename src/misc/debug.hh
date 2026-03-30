#pragma once

[[noreturn]] void unreachable_terminate(const char* filename,
                                        const char* filepos);

[[noreturn]] void not_implemented_terminate(const char* filename,
                                            const char* filepos,
                                            const char* msg);

#define unreachable()                                                          \
  do                                                                           \
    {                                                                          \
      unreachable_terminate(__FILE__, __LINE__);                               \
  } while (false)

#define notimplmented(TODO)                                                    \
  do                                                                           \
    {                                                                          \
      not_implemented_terminate(__FILE__, __LINE__, TODO);                     \
  } while (false)
