#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	class FlockManagerScript
	{
	public:
		// public defaults
		// public functions
		void Update();
		void Update(float x, float y);
		void Render(ConsoleCanvas * canvas);
		// public variables
	protected:
		// protected variables
		std::vector<FlockEntity> entities;
		// protected functions
		static inline bool KEYPRESS(int key) { return (GetKeyState(key) & 0x100) != 0; };
	};

/**************************************************************************************************/