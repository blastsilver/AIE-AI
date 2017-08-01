#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	class FlockEntity
	{
	public:
		// public defaults
		FlockEntity();
		// public functions
		void Update();
		void Update(float x, float y);
		void Render(ConsoleCanvas * canvas);
		void Update(std::vector<FlockEntity> & agents);
		// public variables
		float speed;
		float scale;
		float range;
		float cohesionWeight;
		float alignmentWeight;
		float separationWeight;
		fuse::vec2<float> position;
		fuse::vec2<float> direction;
	protected:
		// protected variables
		ConsoleCanvas::Dot DOT;
		ConsoleCanvas::Text TEXT;
		ConsoleCanvas::Line LINE;
		ConsoleCanvas::Triangle TRIANGLE;
		// protected functions
		static void ROTATE(fuse::vec4<float> & a, const float angle);
		static void NORMALIZE(fuse::vec2<float> & a);
		static float LENGTH(fuse::vec2<float> & a);
		static float PRODUCT_DOT(fuse::vec2<float> & a, fuse::vec2<float> & b);
		static inline bool KEY_PRESS(int key) { return (GetKeyState(key) & 0x100) != 0; };
		fuse::vec2<float> COMPUTE_COHESION(std::vector<FlockEntity> & agents);
		fuse::vec2<float> COMPUTE_ALIGNMENT(std::vector<FlockEntity> & agents);
		fuse::vec2<float> COMPUTE_SEPARATION(std::vector<FlockEntity> & agents);
	};

/**************************************************************************************************/