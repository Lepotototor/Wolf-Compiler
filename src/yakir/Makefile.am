lib_LIBRARIES = libyakir.a

libyakir_a_SOURCES =  \
	yakir_node.hh \
	operand.hh \
	immediate.hh \
	immediate.cc \
	program.hh \
	program.cc \
	func_def.hh \
	func_def.cc \
	ins-list.hh \
	ins-list.cc \
	instruction.hh \
	mov.hh \
	mov.cc \
	ret.hh \
	ret.cc \
	register.cc \
	register.hh


libyakir_a_CPPFLAGS = -I$(top_srcdir)/src -I$(top_srcdir)/src/misc -I$(top_srcdir)/src/driver -I$(top_srcdir)/src/ast_nodes -I$(top_srcdir)/src/visitor

noinst_LIBRARIES = libyakir.a
