#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

namespace ccon
{
	struct WIN32ScreenInfo
	{
		short w;
		short h;
	};
	CCON_DEFINE_HANDLE(WIN32Screen);

	void win32Delete(WIN32Screen * object);
	CCONResult win32Update(WIN32Screen * object, void * handle);
	CCONResult win32Create(WIN32ScreenInfo * info, WIN32Screen * object, void * handle);
}

/**************************************************************************************************/