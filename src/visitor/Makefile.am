lib_LIBRARIES = libvisitor.a

libvisitor_a_SOURCES =  \
  assembly-generation.cc  \
  assembly-generation.hh  \
  assembly-generation.hxx \
  pretty-printer.cc \
  pretty-printer.hh \
  ast_visitor.hh  \
  ast_visitor.hxx \
  asm_visitor.hh  \
  asm_visitor.hxx

libvisitor_a_CPPFLAGS = -I$(top_srcdir)/src -I$(top_srcdir)/src/misc -I$(top_srcdir)/src/driver -I$(top_srcdir)/src/ast_nodes

noinst_LIBRARIES = libvisitor.a
