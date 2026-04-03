# Init the Wolf project
AC_INIT([wolf], [1.0])

# Setup Automake
AM_INIT_AUTOMAKE([subdir-objects] [foreign])

# Pretty display of Makefile rules
AM_SILENT_RULES([no])

# Enable ar for Makefile
AM_PROG_AR

# Check if ranlib is available
AC_PROG_RANLIB

# Check if a C compiler is available
AC_PROG_CXX

CXXFLAGS="$CXXFLAGS -Wall -Wextra -Wold-style-cast -Werror -pedantic -std=c++20"

# Debug option
AC_ARG_ENABLE([debug],
    AS_HELP_STRING([--enable-debug], [Enable debug mode]),
    [enable_debug=yes],
    [enable_debug=no]
)

if test "x$enable_debug" = "xyes"; then
    CXXFLAGS="$CXXFLAGS -fno-builtin -g -O0 -fsanitize=address"
    LDFLAGS="$LDFLAGS -fno-builtin -g -O0 -fsanitize=address"
fi

# List Makefiles in subdirectories
AC_CONFIG_FILES([
                    Makefile
                    src/Makefile
                    src/misc/Makefile
                    src/driver/Makefile
                    src/lexer/Makefile
                    src/parser/Makefile
                    src/ast_nodes/Makefile
                    src/visitor/Makefile
                    src/assembly/Makefile
                ])
AC_OUTPUT
