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
        // protected functions
        static inline bool KeyPress(int key) { return (GetKeyState(key) & 0x100) != 0; };
	};

/**************************************************************************************************/