#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	class Script
	{
	public:
		// public defaults
        inline Script(AI::Grid * grid) { m_grid = grid; };
		// public functions
        virtual inline void Update() {};
        virtual inline void Update(float x, float y) {};
        virtual inline void Render(ConsoleCanvas * canvas) {};
    protected:
        // protected variables
        AI::Grid * m_grid;
        ConsoleCanvas::Dot DOT;
        ConsoleCanvas::Line LINE;
        ConsoleCanvas::Text TEXT;
        ConsoleCanvas::Triangle TRIANGLE;
        // protected functions
        static inline bool KeyPress(int key) { return (GetKeyState(key) & 0x100) != 0; };
	};

/**************************************************************************************************/