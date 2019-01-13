/*
 * Library folder type test program
 *
 * Copyright (C) 2011-2019, Joachim Metz <joachim.metz@gmail.com>
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
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "mapidb_test_libcerror.h"
#include "mapidb_test_libmapidb.h"
#include "mapidb_test_macros.h"
#include "mapidb_test_memory.h"
#include "mapidb_test_unused.h"

/* Tests the libmapidb_folder_initialize function
 * Returns 1 if successful or 0 if not
 */
int mapidb_test_folder_initialize(
     void )
{
	libcerror_error_t *error        = NULL;
	libmapidb_folder_t *folder      = NULL;
	int result                      = 0;

#if defined( HAVE_MAPIDB_TEST_MEMORY )
	int number_of_malloc_fail_tests = 1;
	int number_of_memset_fail_tests = 1;
	int test_number                 = 0;
#endif

	/* Test regular cases
	 */
	result = libmapidb_folder_initialize(
	          &folder,
	          &error );

	MAPIDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	MAPIDB_TEST_ASSERT_IS_NOT_NULL(
	 "folder",
	 folder );

	MAPIDB_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libmapidb_folder_free(
	          &folder,
	          &error );

	MAPIDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	MAPIDB_TEST_ASSERT_IS_NULL(
	 "folder",
	 folder );

	MAPIDB_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libmapidb_folder_initialize(
	          NULL,
	          &error );

	MAPIDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	MAPIDB_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	folder = (libmapidb_folder_t *) 0x12345678UL;

	result = libmapidb_folder_initialize(
	          &folder,
	          &error );

	folder = NULL;

	MAPIDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	MAPIDB_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_MAPIDB_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libmapidb_folder_initialize with malloc failing
		 */
		mapidb_test_malloc_attempts_before_fail = test_number;

		result = libmapidb_folder_initialize(
		          &folder,
		          &error );

		if( mapidb_test_malloc_attempts_before_fail != -1 )
		{
			mapidb_test_malloc_attempts_before_fail = -1;

			if( folder != NULL )
			{
				libmapidb_folder_free(
				 &folder,
				 NULL );
			}
		}
		else
		{
			MAPIDB_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			MAPIDB_TEST_ASSERT_IS_NULL(
			 "folder",
			 folder );

			MAPIDB_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libmapidb_folder_initialize with memset failing
		 */
		mapidb_test_memset_attempts_before_fail = test_number;

		result = libmapidb_folder_initialize(
		          &folder,
		          &error );

		if( mapidb_test_memset_attempts_before_fail != -1 )
		{
			mapidb_test_memset_attempts_before_fail = -1;

			if( folder != NULL )
			{
				libmapidb_folder_free(
				 &folder,
				 NULL );
			}
		}
		else
		{
			MAPIDB_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			MAPIDB_TEST_ASSERT_IS_NULL(
			 "folder",
			 folder );

			MAPIDB_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_MAPIDB_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( folder != NULL )
	{
		libmapidb_folder_free(
		 &folder,
		 NULL );
	}
	return( 0 );
}

/* Tests the libmapidb_folder_free function
 * Returns 1 if successful or 0 if not
 */
int mapidb_test_folder_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libmapidb_folder_free(
	          NULL,
	          &error );

	MAPIDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	MAPIDB_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
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
	 "libmapidb_folder_initialize",
	 mapidb_test_folder_initialize );

	MAPIDB_TEST_RUN(
	 "libmapidb_folder_free",
	 mapidb_test_folder_free );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

