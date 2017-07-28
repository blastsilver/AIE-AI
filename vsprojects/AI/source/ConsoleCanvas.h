#pragma once
/** Dependencies **********************************************************************************/

	#include <ccon3.h>
	#include "fuse\classes.h"

/** Declarations **********************************************************************************/

	class ConsoleCanvas
	{
	public:
		// public structs
		struct Dot
		{
			fuse::vec4<float> v1;
			fuse::vec4<float> c1;
		};
		struct Text
		{
			char * cstring;
			fuse::vec4<float> v1;
			fuse::vec4<float> c1;
		};
		struct Line
		{
			fuse::vec4<float> v1, v2;
			fuse::vec4<float> c1, c2;
		};
		struct Triangle
		{
			fuse::vec4<float> v1, v2, v3;
			fuse::vec4<float> c1, c2, c3;
		};
		// public defaults
		~ConsoleCanvas();
		ConsoleCanvas(int width, int height);
		// public functions
		void clear();
		void render();
		void render(Dot data);
		void render(Text data);
		void render(Line data);
		void render(Triangle data);
		const int getWidth();
		const int getHeight();
	protected:
		// variables
		int m_width;
		int m_height;
		float * m_DBuffer;
		ccon::CCONSurface m_surface;
		ccon::CCONWindow m_oldWindow;
		ccon::CCONWindow m_newWindow;
		// protected functions
		void RASTERIZE(const ConsoleCanvas::Line & data);
		void RASTERIZE(const ConsoleCanvas::Triangle & data);
		void RASTERIZE(const ConsoleCanvas::Dot & data);
		void RASTERIZE(const ConsoleCanvas::Text & data);
		void WORLD_TO_SCREEN(fuse::vec4<float> & point);
		bool RASTERIZE_CHECK(int x, int y, float z, int index);
		void TRIANGLE_SORT_BY_Y(ConsoleCanvas::Triangle & data);
		void TRIANGLE_SORT_BY_Y(fuse::vec4<float> * v, fuse::vec4<float> * c);
		fuse::vec4<float> LERP(const fuse::vec4<float> & a, const fuse::vec4<float> & b, float t);
	};

/**************************************************************************************************/