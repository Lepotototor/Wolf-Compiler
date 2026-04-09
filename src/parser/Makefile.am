lib_LIBRARIES = libparser.a

libparser_a_SOURCES =  \
  parser.cc \
  parser.hh \
  parse-type.cc \
  parse-exp.cc \
  parse-factor.cc \
  parse-declaration.cc \
  parse-external-declaration.cc \
  parse-function-declaration.cc \
  parse-block-item.cc \
  parse-statement.cc

libparser_a_CPPFLAGS = -I$(top_srcdir)/src -I$(top_srcdir)/src/misc -I$(top_srcdir)/src/driver -I$(top_srcdir)/src/lexer -I$(top_srcdir)/src/ast_nodes

noinst_LIBRARIES = libparser.a

