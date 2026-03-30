SUBDIRS =  \
           misc \
		   driver

bin_PROGRAMS = wolf

42sh_SOURCES = wolf.cc

# The %D% represents the current directory
42sh_CPPFLAGS = -I%D%  -I%D%/misc -I%D%/driver

42sh_LDADD =  \
	misc/libmisc.a \
	driver/libdriver.a 
