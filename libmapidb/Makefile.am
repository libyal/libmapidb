AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCNOTIFY_CPPFLAGS@

lib_LTLIBRARIES = libmapidb.la

libmapidb_la_SOURCES = \
	libmapidb.c \
	libmapidb_database.c libmapidb_database.h \
	libmapidb_definitions.h \
	libmapidb_error.c libmapidb_error.h \
	libmapidb_extern.h \
	libmapidb_folder.c libmapidb_folder.h \
	libmapidb_libcerror.h \
	libmapidb_libcnotify.h \
	libmapidb_support.c libmapidb_support.h \
	libmapidb_types.h \
	libmapidb_unused.h

libmapidb_la_LIBADD = \
	@LIBCERROR_LIBADD@ \
	@LIBCNOTIFY_LIBADD@

libmapidb_la_LDFLAGS = -no-undefined -version-info 1:0:0

EXTRA_DIST = \
	libmapidb_definitions.h.in \
	libmapidb.rc \
	libmapidb.rc.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f libmapidb_definitions.h
	/bin/rm -f libmapidb.rc
	/bin/rm -f Makefile

splint:
	@echo "Running splint on libmapidb ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(libmapidb_la_SOURCES)

