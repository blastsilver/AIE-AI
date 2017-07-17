#pragma once
/** Dependencies **********************************************************************************/

	#include "..\..\ccon.h"
	#include <Windows.h>

/** Declarations **********************************************************************************/

	namespace ccon
	{
		struct WIN32Mode_T { DWORD info; };
		struct WIN32Font_T { CONSOLE_FONT_INFOEX info; };
		struct WIN32Style_T { LONG info; };
		struct WIN32Cursor_T { CONSOLE_CURSOR_INFO info; };
		struct WIN32Screen_T { CONSOLE_SCREEN_BUFFER_INFOEX info; };
		struct WIN32Buffer_T { CHAR_INFO * info; SMALL_RECT area; COORD size; };
	}

/**************************************************************************************************/