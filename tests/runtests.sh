#!/bin/sh
# Script to run tests
#
# Version: 20260609

if test -f ${PWD}/libmapidb/.libs/libmapidb.1.dylib && test -f ./pymapidb/.libs/pymapidb.so
then
	install_name_tool -change /usr/local/lib/libmapidb.1.dylib ${PWD}/libmapidb/.libs/libmapidb.1.dylib ./pymapidb/.libs/pymapidb.so
fi

make check-build > /dev/null

make check $@
RESULT=$?

if test ${RESULT} -ne 0
then
	find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

