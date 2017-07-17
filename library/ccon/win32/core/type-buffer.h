#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

namespace ccon
{
	struct WIN32BufferInfo
	{
		short x;
		short y;
		short w;
		short h;
	};

	CCON_DEFINE_HANDLE(WIN32Buffer);

	void win32Delete(WIN32Buffer * object);
	CCONResult win32Update(WIN32Buffer * object, void * handle);
	CCONResult win32Update(WIN32Buffer * object, CCONColour colour, int x, int y);
	CCONResult win32Create(WIN32BufferInfo * info, WIN32Buffer * object, void * handle);
}

/**************************************************************************************************/