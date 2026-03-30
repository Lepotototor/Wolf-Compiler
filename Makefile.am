SUBDIRS = src

debug:
	./configure --enable-debug
	make clean all

check:
	python tests/gen_config.py > /dev/null
	python tests/testsuite.py $(filter-out $@,$(MAKECMDGOALS))
%:
	@:

