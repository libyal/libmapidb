/*
 * Library support functions test program
 *
 * Copyright (C) 2011-2017, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <narrow_string.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "mapidb_test_libmapidb.h"
#include "mapidb_test_macros.h"
#include "mapidb_test_unused.h"

/* Tests the libmapidb_get_version function
 * Returns 1 if successful or 0 if not
 */
int mapidb_test_get_version(
     void )
{
	const char *version_string = NULL;
	int result                 = 0;

	version_string = libmapidb_get_version();

	result = narrow_string_compare(
	          version_string,
	          LIBMAPIDB_VERSION_STRING,
	          9 );

	MAPIDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	return( 1 );

on_error:
	return( 0 );
}

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc MAPIDB_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] MAPIDB_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc MAPIDB_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] MAPIDB_TEST_ATTRIBUTE_UNUSED )
#endif
{
	MAPIDB_TEST_UNREFERENCED_PARAMETER( argc )
	MAPIDB_TEST_UNREFERENCED_PARAMETER( argv )

	MAPIDB_TEST_RUN(
	 "libmapidb_get_version",
	 mapidb_test_get_version );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}
