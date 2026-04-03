SUBDIRS =  \
		   visitor \
		   yakir \
		   ast_nodes \
		   parser \
		   lexer \
           misc \
		   driver

bin_PROGRAMS = wolf

wolf_SOURCES = wolf.cc

# The %D% represents the current directory
wolf_CPPFLAGS = -I%D%  -I%D%/misc -I%D%/driver -I%D%/lexer -I%D%/parser -I%D%/ast_nodes -I%D%/visitor -I%D%/yakir
wolf_LDFLAGS = -lreflex

wolf_LDADD =  \
	driver/libdriver.a \
	parser/libparser.a \
	lexer/liblexer.a \
	ast_nodes/libast_nodes.a \
	visitor/libvisitor.a \
	yakir/libyakir.a \
	misc/libmisc.a
