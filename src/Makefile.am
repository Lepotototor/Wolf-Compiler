SUBDIRS =  \
		   ast_visitor \
		   ast_nodes \
		   lexer \
           misc \
		   driver

bin_PROGRAMS = wolf

wolf_SOURCES = wolf.cc

# The %D% represents the current directory
wolf_CPPFLAGS = -I%D%  -I%D%/misc -I%D%/driver -I%D%/lexer -I%D%/ast_nodes -I%D%/ast_visitor
wolf_LDFLAGS = -lreflex

wolf_LDADD =  \
	driver/libdriver.a \
	ast_nodes/libast_nodes.a \
	ast_visitor/libast_visitor.a \
	lexer/liblexer.a \
	misc/libmisc.a
