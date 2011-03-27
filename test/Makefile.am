if HAVE_LIBGTEST

noinst_PROGRAMS = pdf-extract-outline_test
pdf_extract_outline_test_SOURCES =  $(top_srcdir)/src/pdf-extract.cc pdf-extract-outline_test.cc
AM_CPPFLAGS = -I$(top_srcdir)/src

.PHONY: test

test: $(PROGRAMS)
	for program in $(PROGRAMS); do \
		./$$program; \
	done

else

all:
	@echo "Can't find Google Test http://code.google.com/p/googletest/"

endif
