AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCNOTIFY_CPPFLAGS@ \
	@LIBMAPIDB_DLL_IMPORT@

TESTS = \
	test_library.sh

check_SCRIPTS = \
	test_library.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	mapidb_test_database \
	mapidb_test_error \
	mapidb_test_folder \
	mapidb_test_support

mapidb_test_database_SOURCES = \
	mapidb_test_database.c \
	mapidb_test_libcerror.h \
	mapidb_test_libmapidb.h \
	mapidb_test_macros.h \
	mapidb_test_memory.c mapidb_test_memory.h \
	mapidb_test_unused.h

mapidb_test_database_LDADD = \
	../libmapidb/libmapidb.la \
	@LIBCERROR_LIBADD@

mapidb_test_error_SOURCES = \
	mapidb_test_error.c \
	mapidb_test_libmapidb.h \
	mapidb_test_macros.h \
	mapidb_test_unused.h

mapidb_test_error_LDADD = \
	../libmapidb/libmapidb.la

mapidb_test_folder_SOURCES = \
	mapidb_test_folder.c \
	mapidb_test_libcerror.h \
	mapidb_test_libmapidb.h \
	mapidb_test_macros.h \
	mapidb_test_memory.c mapidb_test_memory.h \
	mapidb_test_unused.h

mapidb_test_folder_LDADD = \
	../libmapidb/libmapidb.la \
	@LIBCERROR_LIBADD@

mapidb_test_support_SOURCES = \
	mapidb_test_libmapidb.h \
	mapidb_test_macros.h \
	mapidb_test_support.c \
	mapidb_test_unused.h

mapidb_test_support_LDADD = \
	../libmapidb/libmapidb.la

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

