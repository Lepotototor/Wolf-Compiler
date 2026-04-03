lib_LIBRARIES = libassembly.a

libassembly_a_SOURCES =  \
	assembly_node.hh \
	operand.hh \
	immediate.hh \
	program.hh \
	func_def.hh \
	ins-list.hh \
	instruction.hh \
	mov.hh \
	ret.hh \
	register.hh


libassembly_a_CPPFLAGS = -I$(top_srcdir)/src -I$(top_srcdir)/src/misc -I$(top_srcdir)/src/driver -I$(top_srcdir)/src/ast_nodes -I$(top_srcdir)/src/ast_visitor

noinst_LIBRARIES = libassembly.a
