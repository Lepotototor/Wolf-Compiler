# Init the 42sh project
AC_INIT([Wolf-Compiler], [1.0])

# Setup Automake
AM_INIT_AUTOMAKE([subdir-objects] [foreign])

# Pretty display of Makefile rules
AM_SILENT_RULES([yes])

# Enable ar for Makefile
AM_PROG_AR

# Check if ranlib is available
AC_PROG_RANLIB

# Check if a C compiler is available
AC_PROG_CC

CFLAGS="$CFLAGS -std=c99 -pedantic -Werror -Wall -Wextra -Wvla"

# Debug option
AC_ARG_ENABLE([debug],
    AS_HELP_STRING([--enable-debug], [Enable debug mode]),
    [enable_debug=yes],
    [enable_debug=no]
)

if test "x$enable_debug" = "xyes"; then
    CFLAGS="$CFLAGS -fno-builtin -g -O0 -fsanitize=address"
    LDFLAGS="$LDFLAGS -fno-builtin -g -O0 -fsanitize=address"
fi

# List Makefiles in subdirectories
AC_CONFIG_FILES([
                    Makefile
                    src/Makefile
                ])
AC_OUTPUT
