#pragma once

namespace ccon
{
	struct WIN32WindowInfo
	{
		ccon::WIN32FontInfo fontInfo;
		ccon::WIN32ModeInfo modeIInfo;
		ccon::WIN32ModeInfo modeOInfo;
		ccon::WIN32StyleInfo styleInfo;
		ccon::WIN32ScreenInfo screenInfo;
		ccon::WIN32CursorInfo cursorInfo;
	};
	CCON_DEFINE_HANDLE(WIN32Window);

	void win32Delete(WIN32Window * object);
	CCONResult win32Update(WIN32Window * object);
	CCONResult win32Create(WIN32WindowInfo * info, WIN32Window * object);
}