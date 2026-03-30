SUBDIRS =  \
           misc \
		   driver

bin_PROGRAMS = wolf

wolf_SOURCES = wolf.cc

# The %D% represents the current directory
wolf_CPPFLAGS = -I%D%  -I%D%/misc -I%D%/driver

wolf_LDADD =  \
	misc/libmisc.a \
	driver/libdriver.a 
