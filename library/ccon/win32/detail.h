#pragma once

#include "..\ccon.h"
#include "core\detail.h"
#include "core\type-font.h"
#include "core\type-mode.h"
#include "core\type-style.h"
#include "core\type-buffer.h"
#include "core\type-cursor.h"
#include "core\type-screen.h"

namespace ccon
{
	struct WIN32Window_T
	{
		WIN32Font font;
		WIN32Mode modeI;
		WIN32Mode modeO;
		WIN32Style style;
		WIN32Screen screen;
		WIN32Cursor cursor;
	};
}