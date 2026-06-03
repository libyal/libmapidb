#!/bin/sh
# Script to run tests
#
# Version: 20260602

if test -f ${PWD}/libmapidb/.libs/libmapidb.1.dylib && test -f ./pymapidb/.libs/pymapidb.so
then
	install_name_tool -change /usr/local/lib/libmapidb.1.dylib ${PWD}/libmapidb/.libs/libmapidb.1.dylib ./pymapidb/.libs/pymapidb.so
fi

make check $@
RESULT=$?

if test ${RESULT} -ne 0 && test -f tests/test-suite.log
then
	cat tests/test-suite.log
fi
exit ${RESULT}

