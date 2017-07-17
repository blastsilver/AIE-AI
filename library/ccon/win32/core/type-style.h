#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	namespace ccon
	{
		struct WIN32StyleInfo
		{
			int32 data;
		};
		CCON_DEFINE_HANDLE(WIN32Style);

		void win32Delete(WIN32Style * object);
		CCONResult win32Update(WIN32Style * object, int index);
		CCONResult win32Create(WIN32StyleInfo * info, WIN32Style * object, int index);
	}

/**************************************************************************************************/