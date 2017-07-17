#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	namespace ccon
	{
		struct WIN32FontInfo
		{
			short w;
			short h;
			uint family;
			uint weight;
			char name[32];
		};
		CCON_DEFINE_HANDLE(WIN32Font);

		void win32Delete(WIN32Font * object);
		CCONResult win32Update(WIN32Font * object, void * handle);
		CCONResult win32Create(WIN32FontInfo * info, WIN32Font * object, void * handle);
	}

/**************************************************************************************************/