AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCSTRING_CPPFLAGS@ \
	@LIBCERROR_CPPFLAGS@ \
	@LIBMAPIDB_DLL_IMPORT@

TESTS = \
	test_api_functions.sh

check_SCRIPTS = \
	test_api_functions.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	mapidb_test_get_version

mapidb_test_get_version_SOURCES = \
	mapidb_test_libmapidb.h \
	mapidb_test_libcstring.h \
	mapidb_test_get_version.c \
	mapidb_test_unused.h

mapidb_test_get_version_LDADD = \
	../libmapidb/libmapidb.la \
	@LIBCSTRING_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

