noinst_PROGRAMS = pdf-extract-outline_test
pdf_extract_outline_test_SOURCES =  $(top_srcdir)/src/pdf-extract.cc pdf-extract-outline_test.cc
pdf_extract_outline_test_LDADD = $(GLIB_LIBS) -lgtest
AM_CPPFLAGS = $(GLIB_CFLAGS) -I$(top_srcdir)/src

.PHONY: test

test: $(PROGRAMS)
	for program in $(PROGRAMS); do \
		./$$program; \
	done
