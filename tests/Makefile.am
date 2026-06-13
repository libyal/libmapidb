AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCNOTIFY_CPPFLAGS@ \
	@LIBMAPIDB_DLL_IMPORT@

BUILT_SOURCES = package.m4

check_AUTOTESTS = \
	test_library \
	test_manpages

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

AUTOM4TE = autom4te
AUTOTEST = $(AUTOM4TE) --language=autotest

SUFFIXES = .at

.at:
	$(AM_V_GEN)rm -f $@ $@.tmp; \
	$(AUTOTEST) -I '$(srcdir)' -o $@.tmp $< && \
	mv $@.tmp $@

atconfig: $(top_builddir)/config.status
	cd $(top_builddir) && $(SHELL) ./config.status tests/$@

check-build: $(check_PROGRAMS)

check-local: $(check_AUTOTESTS)
	@fail=0; \
	for test_suite in $(check_AUTOTESTS); do \
		$(AM_TESTS_ENVIRONMENT) $(SHELL) "./$$test_suite" $(TESTSUITEFLAGS) || fail=1; \
		echo ""; \
	done; \
	exit $$fail

clean-local:
	for test_suite in $(check_AUTOTESTS); do \
		test ! -f "$$test_suite" || $(SHELL) "./$$test_suite" --clean; \
	done

package.m4: $(top_srcdir)/configure.ac
	$(AM_V_GEN):; \
	{ \
	  echo 'm4_define([AT_PACKAGE_NAME], [$(PACKAGE_NAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_TARNAME], [$(PACKAGE_TARNAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_VERSION], [$(PACKAGE_VERSION)])' ; \
	  echo 'm4_define([AT_PACKAGE_STRING], [$(PACKAGE_STRING)])' ; \
	  echo 'm4_define([AT_PACKAGE_BUGREPORT], [$(PACKAGE_BUGREPORT)])' ; \
	} > $@

test_library: package.m4 test_library.at test_macros.at

test_manpages: package.m4 test_manpages.at

EXTRA_DIST = \
	$(check_AUTOTESTS:=.at) \
	package.m4 \
	test_macros.at

CLEANFILES = \
	$(check_AUTOTESTS) \
	*.exe \
	*.tmp

DISTCLEANFILES = \
	*.log \
	atconfig \
	Makefile \
	Makefile.in

