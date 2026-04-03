lib_LIBRARIES = libvisitor.a

libvisitor_a_SOURCES =  \
  yakir-generation.cc  \
  yakir-generation.hh  \
  yakir-generation.hxx \
  code-emission.hh \
  code-emission.cc \
  pretty-printer.cc \
  pretty-printer.hh \
  ast_visitor.hh  \
  ast_visitor.hxx \
  yakir_visitor.hh  \
  yakir_visitor.hxx

libvisitor_a_CPPFLAGS = -I$(top_srcdir)/src -I$(top_srcdir)/src/misc -I$(top_srcdir)/src/driver -I$(top_srcdir)/src/ast_nodes

noinst_LIBRARIES = libvisitor.a
