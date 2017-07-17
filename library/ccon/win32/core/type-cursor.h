#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	namespace ccon
	{
		struct WIN32CursorInfo
		{
			int visible;
			uint32 size;
		};
		CCON_DEFINE_HANDLE(WIN32Cursor);

		void win32Delete(WIN32Cursor * object);
		CCONResult win32Update(WIN32Cursor * object, void * handle);
		CCONResult win32Create(WIN32CursorInfo * info, WIN32Cursor * object, void * handle);
	}

/**************************************************************************************************/