#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

namespace ccon
{
	struct WIN32ModeInfo
	{
		uint32 data;
	};
	CCON_DEFINE_HANDLE(WIN32Mode);

	void win32Delete(WIN32Mode * object);
	CCONResult win32Update(WIN32Mode * object, void * handle);
	CCONResult win32Create(WIN32ModeInfo * info, WIN32Mode * object, void * handle);
}

/**************************************************************************************************/