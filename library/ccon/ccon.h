#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	// preprocessor constants
	#define CCON_NULL 0
	#define CCON_TRUE 1
	#define CCON_FALSE 0
	#define CCON_ISNULL(object) object == 0
	#define CCON_DELETE_ARRAY(object) if (object != 0) { delete[]object; object = 0; }
	#define CCON_DELETE_OBJECT(object) if (object != 0) { delete object; object = 0; }
	#define CCON_DEFINE_HANDLE(object) typedef struct object##_T* object;

	namespace ccon
	{
		// signed types
		typedef signed char        byte;
		typedef signed char        int8;
		typedef signed short       int16;
		typedef signed long        int32;
		typedef signed long long   int64;

		// unsigned types
		typedef unsigned int       uint;
		typedef unsigned char      uint8;
		typedef unsigned short     uint16;
		typedef unsigned long      uint32;
		typedef unsigned long long uint64;

		// result enums
		enum CCONResult
		{
			CCON_SUCCESS,
			CCON_FAILURE,
		};

		// constant enums
		enum CCONEnum
		{

		};

		// basic structures
		struct CCONPixel { float x, y, r, g, b; };
	}

/**************************************************************************************************/