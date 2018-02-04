/*
 * The error code definitions for libmapidb
 *
 * Copyright (C) 2011-2018, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _LIBMAPIDB_ERROR_H )
#define _LIBMAPIDB_ERROR_H

#include <libmapidb/types.h>

/* External error type definition hides internal structure
 */
typedef intptr_t libmapidb_error_t;

/* The error domains
 */
enum LIBMAPIDB_ERROR_DOMAINS
{
	LIBMAPIDB_ERROR_DOMAIN_ARGUMENTS		= (int) 'a',
	LIBMAPIDB_ERROR_DOMAIN_CONVERSION		= (int) 'c',
	LIBMAPIDB_ERROR_DOMAIN_COMPRESSION		= (int) 'C',
	LIBMAPIDB_ERROR_DOMAIN_IO			= (int) 'I',
	LIBMAPIDB_ERROR_DOMAIN_INPUT			= (int) 'i',
	LIBMAPIDB_ERROR_DOMAIN_MEMORY			= (int) 'm',
	LIBMAPIDB_ERROR_DOMAIN_OUTPUT			= (int) 'o',
	LIBMAPIDB_ERROR_DOMAIN_RUNTIME			= (int) 'r'
};

/* The argument error codes
 * to signify errors regarding arguments passed to a function
 */
enum LIBMAPIDB_ARGUMENT_ERROR
{
	LIBMAPIDB_ARGUMENT_ERROR_GENERIC		= 0,

	/* The argument contains an invalid value
	 */
	LIBMAPIDB_ARGUMENT_ERROR_INVALID_VALUE		= 1,

	/* The argument contains a value less than zero
	 */
	LIBMAPIDB_ARGUMENT_ERROR_VALUE_LESS_THAN_ZERO	= 2,

	/* The argument contains a value zero or less
	 */
	LIBMAPIDB_ARGUMENT_ERROR_VALUE_ZERO_OR_LESS	= 3,

	/* The argument contains a value that exceeds the maximum
	 * for the specific type
	 */
	LIBMAPIDB_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM	= 4,

	/* The argument contains a value that is too small
	 */
	LIBMAPIDB_ARGUMENT_ERROR_VALUE_TOO_SMALL	= 5,

	/* The argument contains a value that is too large
	 */
	LIBMAPIDB_ARGUMENT_ERROR_VALUE_TOO_LARGE	= 6,

	/* The argument contains a value that is out of bounds
	 */
	LIBMAPIDB_ARGUMENT_ERROR_VALUE_OUT_OF_BOUNDS	= 7,

	/* The argument contains a value that is not supported
	 */
	LIBMAPIDB_ARGUMENT_ERROR_UNSUPPORTED_VALUE	= 8,

	/* The argument contains a value that conficts with another argument
	 */
	LIBMAPIDB_ARGUMENT_ERROR_CONFLICTING_VALUE	= 9
};

/* The conversion error codes
 * to signify errors regarding conversions
 */
enum LIBMAPIDB_CONVERSION_ERROR
{
	LIBMAPIDB_CONVERSION_ERROR_GENERIC		= 0,

	/* The conversion failed on the input
	 */
	LIBMAPIDB_CONVERSION_ERROR_INPUT_FAILED		= 1,

	/* The conversion failed on the output
	 */
	LIBMAPIDB_CONVERSION_ERROR_OUTPUT_FAILED	= 2
};

/* The compression error codes
 * to signify errors regarding compression
 */
enum LIBMAPIDB_COMPRESSION_ERROR
{
	LIBMAPIDB_COMPRESSION_ERROR_GENERIC		= 0,

	/* The compression failed
	 */
	LIBMAPIDB_COMPRESSION_ERROR_COMPRESS_FAILED	= 1,

	/* The decompression failed
	 */
	LIBMAPIDB_COMPRESSION_ERROR_DECOMPRESS_FAILED	= 2
};

/* The input/output error codes
 * to signify errors regarding input/output
 */
enum LIBMAPIDB_IO_ERROR
{
	LIBMAPIDB_IO_ERROR_GENERIC			= 0,

	/* The open failed
	 */
	LIBMAPIDB_IO_ERROR_OPEN_FAILED			= 1,

	/* The close failed
	 */
	LIBMAPIDB_IO_ERROR_CLOSE_FAILED			= 2,

	/* The seek failed
	 */
	LIBMAPIDB_IO_ERROR_SEEK_FAILED			= 3,

	/* The read failed
	 */
	LIBMAPIDB_IO_ERROR_READ_FAILED			= 4,

	/* The write failed
	 */
	LIBMAPIDB_IO_ERROR_WRITE_FAILED			= 5,

	/* Access denied
	 */
	LIBMAPIDB_IO_ERROR_ACCESS_DENIED		= 6,

	/* The resource is invalid i.e. a missing file
	 */
	LIBMAPIDB_IO_ERROR_INVALID_RESOURCE		= 7,

	/* The ioctl failed
	 */
	LIBMAPIDB_IO_ERROR_IOCTL_FAILED			= 8,

	/* The unlink failed
	 */
	LIBMAPIDB_IO_ERROR_UNLINK_FAILED		= 9
};

/* The input error codes
 * to signify errors regarding handing input data
 */
enum LIBMAPIDB_INPUT_ERROR
{
	LIBMAPIDB_INPUT_ERROR_GENERIC			= 0,

	/* The input contains invalid data
	 */
	LIBMAPIDB_INPUT_ERROR_INVALID_DATA		= 1,

	/* The input contains an unsupported signature
	 */
	LIBMAPIDB_INPUT_ERROR_SIGNATURE_MISMATCH	= 2,

	/* A checksum in the input did not match
	 */
	LIBMAPIDB_INPUT_ERROR_CHECKSUM_MISMATCH		= 3,

	/* A value in the input did not match a previously
	 * read value or calculated value
	 */
	LIBMAPIDB_INPUT_ERROR_VALUE_MISMATCH		= 4
};

/* The memory error codes
 * to signify errors regarding memory
 */
enum LIBMAPIDB_MEMORY_ERROR
{
	LIBMAPIDB_MEMORY_ERROR_GENERIC			= 0,

	/* There is insufficient memory available
	 */
	LIBMAPIDB_MEMORY_ERROR_INSUFFICIENT		= 1,

	/* The memory failed to be copied
	 */
	LIBMAPIDB_MEMORY_ERROR_COPY_FAILED		= 2,

	/* The memory failed to be set
	 */
	LIBMAPIDB_MEMORY_ERROR_SET_FAILED		= 3
};

/* The output error codes
 */
enum LIBMAPIDB_OUTPUT_ERROR
{
	LIBMAPIDB_OUTPUT_ERROR_GENERIC			= 0,

	/* There is insuficient space to write the output
	 */
	LIBMAPIDB_OUTPUT_ERROR_INSUFFICIENT_SPACE	= 1
};

/* The runtime error codes
 * to signify errors regarding runtime processing
 */
enum LIBMAPIDB_RUNTIME_ERROR
{
	LIBMAPIDB_RUNTIME_ERROR_GENERIC			= 0,

	/* The value is missing
	 */
	LIBMAPIDB_RUNTIME_ERROR_VALUE_MISSING		= 1,

	/* The value was already set
	 */
	LIBMAPIDB_RUNTIME_ERROR_VALUE_ALREADY_SET	= 2,

	/* The creation and/or initialization of an internal structure failed
	 */
	LIBMAPIDB_RUNTIME_ERROR_INITIALIZE_FAILED	= 3,

	/* The resize of an internal structure failed
	 */
	LIBMAPIDB_RUNTIME_ERROR_RESIZE_FAILED		= 4,

	/* The free and/or finalization of an internal structure failed
	 */
	LIBMAPIDB_RUNTIME_ERROR_FINALIZE_FAILED		= 5,

	/* The value could not be determined
	 */
	LIBMAPIDB_RUNTIME_ERROR_GET_FAILED		= 6,

	/* The value could not be set
	 */
	LIBMAPIDB_RUNTIME_ERROR_SET_FAILED		= 7,

	/* The value could not be appended/prepended
	 */
	LIBMAPIDB_RUNTIME_ERROR_APPEND_FAILED		= 8,

	/* The value could not be copied
	 */
	LIBMAPIDB_RUNTIME_ERROR_COPY_FAILED		= 9,

	/* The value could not be removed
	 */
	LIBMAPIDB_RUNTIME_ERROR_REMOVE_FAILED		= 10,

	/* The value could not be printed
	 */
	LIBMAPIDB_RUNTIME_ERROR_PRINT_FAILED		= 11,

	/* The value was out of bounds
	 */
	LIBMAPIDB_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS	= 12,

	/* The value exceeds the maximum for its specific type
	 */
	LIBMAPIDB_RUNTIME_ERROR_VALUE_EXCEEDS_MAXIMUM	= 13,

	/* The value is unsupported
	 */
	LIBMAPIDB_RUNTIME_ERROR_UNSUPPORTED_VALUE	= 14,

	/* An abort was requested
	 */
	LIBMAPIDB_RUNTIME_ERROR_ABORT_REQUESTED		= 15
};

#endif /* !defined( _LIBMAPIDB_ERROR_H ) */

