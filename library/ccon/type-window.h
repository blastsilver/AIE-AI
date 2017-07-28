#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	namespace ccon
	{
		struct CCONWindowInfo
		{
			short w;
			short h;
		};
		CCON_DEFINE_HANDLE(CCONWindow);

		CCONResult cconDelete(CCONWindow * object);
		CCONResult cconUpdate(CCONWindow * object);
		CCONResult cconCreate(CCONWindow * object, CCONWindowInfo * info);
	}

/**************************************************************************************************/