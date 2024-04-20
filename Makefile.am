ACLOCAL_AMFLAGS = -I m4

SUBDIRS = \
	include \
	common \
	libcerror \
	libcnotify \
	libmapidb \
	po \
	manuals \
	tests \
	msvscpp

DPKG_FILES = \
	dpkg/changelog \
	dpkg/changelog.in \
	dpkg/compat \
	dpkg/control \
	dpkg/copyright \
	dpkg/rules \
	dpkg/libmapidb-dev.install \
	dpkg/libmapidb.install \
	dpkg/source/format

GETTEXT_FILES = \
	config.rpath \
	po/Makevars.in

PKGCONFIG_FILES = \
	libmapidb.pc.in

SPEC_FILES = \
	libmapidb.spec \
	libmapidb.spec.in

EXTRA_DIST = \
	$(DPKG_FILES) \
	$(GETTEXT_FILES) \
	$(PKGCONFIG_FILES) \
	$(SPEC_FILES)

DISTCLEANFILES = \
	config.status \
	config.cache \
	config.log \
	libmapidb.pc \
	libmapidb.spec \
	Makefile \
	Makefile.in \
	po/Makevars

pkgconfigdir = $(libdir)/pkgconfig

pkgconfig_DATA = \
	libmapidb.pc

libtool: @LIBTOOL_DEPS@
	cd $(srcdir) && $(SHELL) ./config.status --recheck

lib: library

library:
	cd $(srcdir)/common && $(MAKE) $(AM_MAKEFLAGS)
	cd $(srcdir)/libcerror && $(MAKE) $(AM_MAKEFLAGS)
	cd $(srcdir)/libcnotify && $(MAKE) $(AM_MAKEFLAGS)
	cd $(srcdir)/libmapidb && $(MAKE) $(AM_MAKEFLAGS)
	cd $(srcdir)/po && $(MAKE) $(AM_MAKEFLAGS)

