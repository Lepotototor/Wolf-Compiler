SUBDIRS =  \
		   ast_nodes \
		   lexer \
           misc \
		   driver

bin_PROGRAMS = wolf

wolf_SOURCES = wolf.cc

# The %D% represents the current directory
wolf_CPPFLAGS = -I%D%  -I%D%/misc -I%D%/driver -I%D%/lexer -I%D%/ast_nodes
wolf_LDFLAGS = -lreflex

wolf_LDADD =  \
	driver/libdriver.a \
	lexer/libast_nodes.a \
	lexer/liblexer.a \
	misc/libmisc.a
