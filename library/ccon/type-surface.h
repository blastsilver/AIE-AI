#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	namespace ccon
	{
		struct CCONSurfaceInfo
		{
			short x;
			short y;
			short w;
			short h;
		};

		struct CCONSurfaceWriteInfo1
		{
			CCONCOORD coord;
			CCONRGB colour;
		};

		struct CCONSurfaceWriteInfo2
		{
			char * cstring;
			CCONCOORD coord;
			CCONRGB colour;
		};

		CCON_DEFINE_HANDLE(CCONSurface);

		CCONResult cconDelete(CCONSurface * object);
		CCONResult cconUpdate(CCONSurface * object);
		CCONResult cconCreate(CCONSurface * object, CCONSurfaceInfo * info);
		CCONResult cconUpdate(CCONSurface * object, const CCONSurfaceWriteInfo1 & info);
		CCONResult cconUpdate(CCONSurface * object, const CCONSurfaceWriteInfo2 & info);
	}

/**************************************************************************************************/