lib_LIBRARIES = liblexer.a

liblexer_a_SOURCES =  \
  lexer.cc \
  lexer.hh \
  scan-wolf.cc \
  scan-wolf.hh \
  token.cc \
  token.hh

liblexer_a_CPPFLAGS = -I$(top_srcdir)/src -I$(top_srcdir)/src/misc -I$(top_srcdir)/src/driver

%D%/scan-wolf.cc %D%/scan-wolf.hh: %D%/scan-wolf.ll
	reflex $^  -d --flex --header-file=%D%/scan-wolf.hh -o %D%/scan-wolf.cc

noinst_LIBRARIES = liblexer.a

