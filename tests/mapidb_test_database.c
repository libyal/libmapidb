/*
 * Library database type test program
 *
 * Copyright (C) 2011-2020, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
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

#include "../libmapidb/libmapidb_database.h"

/* Tests the libmapidb_database_initialize function
 * Returns 1 if successful or 0 if not
 */
int mapidb_test_database_initialize(
     void )
{
	libcerror_error_t *error        = NULL;
	libmapidb_database_t *database  = NULL;
	int result                      = 0;

#if defined( HAVE_MAPIDB_TEST_MEMORY )
	int number_of_malloc_fail_tests = 1;
	int number_of_memset_fail_tests = 1;
	int test_number                 = 0;
#endif

	/* Test regular cases
	 */
	result = libmapidb_database_initialize(
	          &database,
	          &error );

	MAPIDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	MAPIDB_TEST_ASSERT_IS_NOT_NULL(
	 "database",
	 database );

	MAPIDB_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libmapidb_database_free(
	          &database,
	          &error );

	MAPIDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	MAPIDB_TEST_ASSERT_IS_NULL(
	 "database",
	 database );

	MAPIDB_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libmapidb_database_initialize(
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

	database = (libmapidb_database_t *) 0x12345678UL;

	result = libmapidb_database_initialize(
	          &database,
	          &error );

	database = NULL;

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
		/* Test libmapidb_database_initialize with malloc failing
		 */
		mapidb_test_malloc_attempts_before_fail = test_number;

		result = libmapidb_database_initialize(
		          &database,
		          &error );

		if( mapidb_test_malloc_attempts_before_fail != -1 )
		{
			mapidb_test_malloc_attempts_before_fail = -1;

			if( database != NULL )
			{
				libmapidb_database_free(
				 &database,
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
			 "database",
			 database );

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
		/* Test libmapidb_database_initialize with memset failing
		 */
		mapidb_test_memset_attempts_before_fail = test_number;

		result = libmapidb_database_initialize(
		          &database,
		          &error );

		if( mapidb_test_memset_attempts_before_fail != -1 )
		{
			mapidb_test_memset_attempts_before_fail = -1;

			if( database != NULL )
			{
				libmapidb_database_free(
				 &database,
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
			 "database",
			 database );

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
	if( database != NULL )
	{
		libmapidb_database_free(
		 &database,
		 NULL );
	}
	return( 0 );
}

/* Tests the libmapidb_database_free function
 * Returns 1 if successful or 0 if not
 */
int mapidb_test_database_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libmapidb_database_free(
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

#if defined( TODO )

/* Tests the libmapidb_database_get_root_folder function
 * Returns 1 if successful or 0 if not
 */
int mapidb_test_database_get_root_folder(
     void )
{
	libcerror_error_t *error        = NULL;
	libmapidb_database_t *database  = NULL;
	libmapidb_folder_t *root_folder = 0;
	int result                      = 0;
	int root_folder_is_set          = 0;

	/* Initialize test
	 */
	result = libmapidb_database_initialize(
	          &database,
	          &error );

	MAPIDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	MAPIDB_TEST_ASSERT_IS_NOT_NULL(
	 "database",
	 database );

	MAPIDB_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libmapidb_database_get_root_folder(
	          database,
	          &root_folder,
	          &error );

	MAPIDB_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	MAPIDB_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	root_folder_is_set = result;

	if( root_folder_is_set != 0 )
	{
		MAPIDB_TEST_ASSERT_IS_NOT_NULL(
		 "root_folder",
		 root_folder );

		result = libmapidb_folder_free(
		          &root_folder,
		          &error );

		MAPIDB_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		MAPIDB_TEST_ASSERT_IS_NULL(
		 "error",
		 error );
	}
	/* Test error cases
	 */
	result = libmapidb_database_get_root_folder(
	          NULL,
	          &root_folder,
	          &error );

	MAPIDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	MAPIDB_TEST_ASSERT_IS_NULL(
	 "root_folder",
	 root_folder );

	MAPIDB_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( root_folder_is_set != 0 )
	{
		result = libmapidb_database_get_root_folder(
		          database,
		          NULL,
		          &error );

		MAPIDB_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		MAPIDB_TEST_ASSERT_IS_NULL(
		 "root_folder",
		 root_folder );

		MAPIDB_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libmapidb_database_free(
	          &database,
	          &error );

	MAPIDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	MAPIDB_TEST_ASSERT_IS_NULL(
	 "database",
	 database );

	MAPIDB_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( root_folder != NULL )
	{
		libmapidb_folder_free(
		 &root_folder,
		 NULL );
	}
	if( database != NULL )
	{
		libmapidb_database_free(
		 &database,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( TODO ) */

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
	 "libmapidb_database_initialize",
	 mapidb_test_database_initialize );

	MAPIDB_TEST_RUN(
	 "libmapidb_database_free",
	 mapidb_test_database_free );

#if defined( TODO )

	MAPIDB_TEST_RUN(
	 "libmapidb_database_get_root_folder",
	 mapidb_test_database_get_root_folder );

#endif /* defined( TODO ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

