#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	class ScriptNodeRemover
	{
	public:
		// public defaults
		ScriptNodeRemover(AI::Grid * grid);
		// public functions
		void Update();
		void Render(ConsoleCanvas * canvas);

	protected:
		// variables
		AI::Grid * m_grid;
		bool m_keyPress;
		bool m_mouseClick;
		bool m_mouseClick1;
		bool m_mouseClick2;
		fuse::vec2<float> m_pos1;
		fuse::vec2<float> m_pos2;
		// [Rendering] variables
		ConsoleCanvas::Line m_line;
		// protected functions
		bool ValidateCursorPos(POINT * pt, RECT * rect);
		fuse::vec2<float> CalculateCursorPos(POINT * pt, RECT * rect);
	};

/**************************************************************************************************/