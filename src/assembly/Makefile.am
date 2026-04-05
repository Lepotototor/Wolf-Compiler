lib_LIBRARIES = libassembly.a

libassembly_a_SOURCES =  \
	code-emission.hh \
	code-emission.cc \
	assembly_node.hh \
	operand.hh \
	immediate.hh \
	immediate.cc \
	program.hh \
	program.cc \
	func_def.hh \
	func_def.cc \
	instruction.hh \
	mov.hh \
	mov.cc \
	ret.hh \
	ret.cc \
	unary.hh \
	unary.cc \
	register.cc \
	register.hh \
	pseudo.hh \
	pseudo.cc \
	stack.hh \
	stack.cc \
	allocate-stack.hh \
	allocate-stack.cc


libassembly_a_CPPFLAGS = -I$(top_srcdir)/src -I$(top_srcdir)/src/misc -I$(top_srcdir)/src/driver -I$(top_srcdir)/src/ast_nodes -I$(top_srcdir)/src/visitor

noinst_LIBRARIES = libassembly.a
