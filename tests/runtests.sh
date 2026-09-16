#!/bin/sh
# Script to run tests
#
# Version: 20260714

if [ -f "${PWD}/libmapidb/.libs/libmapidb.1.dylib" ] && [ -f ./pymapidb/.libs/pymapidb.so ]
then
    install_name_tool -change /usr/local/lib/libmapidb.1.dylib "${PWD}/libmapidb/.libs/libmapidb.1.dylib" ./pymapidb/.libs/pymapidb.so
fi

make check-build > /dev/null

# shellcheck disable=SC2068
make check $@
RESULT=$?

if [ ${RESULT} -ne 0 ]
then
    find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

