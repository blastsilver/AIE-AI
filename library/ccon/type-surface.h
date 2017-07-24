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
		CCON_DEFINE_HANDLE(CCONSurface);

		CCONResult cconDelete(CCONSurface * object);
		CCONResult cconUpdate(CCONSurface * object);
		CCONResult cconUpdate(CCONSurface * object, const CCONPixel & data);
		CCONResult cconCreate(CCONSurfaceInfo * info, CCONSurface * object);
	}

/**************************************************************************************************/