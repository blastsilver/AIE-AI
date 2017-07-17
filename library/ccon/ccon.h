#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	namespace ccon
	{
		// signed types
		typedef signed char      byte;
		typedef signed char      int8;
		typedef signed short     int16;
		typedef signed long      int32;
		typedef signed long long int64;

		// unsigned types
		typedef unsigned int       uint;
		typedef unsigned char      uint8;
		typedef unsigned short     uint16;
		typedef unsigned long      uint32;
		typedef unsigned long long uint64;

		// enums
		enum CCONenum
		{

		};
		enum CCONResult
		{
			CCON_SUCCESS,
			CCON_FAILURE,
		};

		// structures
		struct CCONColour
		{
			float r, g, b;
		};
	}

	// preprocessor constants
	#define CCON_NULL 0
	#define CCON_TRUE 1
	#define CCON_FALSE 0
	// preprocessor functions
	#define CCON_ISNULL(object) object == 0
	#define CCON_DELETE_ARRAY(object) if (!CCON_ISNULL(object)) delete[]object; object = 0;
	#define CCON_DEFINE_HANDLE(object) typedef struct object##_T* object;
	#define CCON_DELETE_OBJECT(object) if (!CCON_ISNULL(object)) delete object; object = 0;

/**************************************************************************************************/