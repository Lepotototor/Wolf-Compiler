lib_LIBRARIES = libyakir.a

libyakir_a_SOURCES =  \
	yakir_node.hh \
	pretty_printer.hh \
	pretty_printer.cc \
	program.hh \
	program.cc \
	val.hh \
	constant.hh \
	constant.cc \
	var.hh \
	var.cc \
	func_def.hh \
	func_def.cc \
	instruction.hh \
	unary.hh \
	unary.cc \
	binary.hh \
	binary.cc \
	ret.hh \
	ret.cc


libyakir_a_CPPFLAGS = -I$(top_srcdir)/src -I$(top_srcdir)/src/misc -I$(top_srcdir)/src/driver -I$(top_srcdir)/src/ast_nodes -I$(top_srcdir)/src/visitor

noinst_LIBRARIES = libyakir.a
