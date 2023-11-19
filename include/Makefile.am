include_HEADERS = \
	libmapidb.h

pkginclude_HEADERS = \
	libmapidb/definitions.h \
	libmapidb/error.h \
	libmapidb/extern.h \
	libmapidb/features.h \
	libmapidb/types.h

EXTRA_DIST = \
	libmapidb.h.in \
	libmapidb/definitions.h.in \
	libmapidb/features.h.in \
	libmapidb/types.h.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	-rm -f libmapidb.h
	-rm -f libmapidb/definitions.h
	-rm -f libmapidb/features.h
	-rm -f libmapidb/types.h
	-rm -f Makefile

