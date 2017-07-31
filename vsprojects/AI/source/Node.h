#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

    namespace AI
    {
	    class Node
	    {
	    public:
		    // public defaults
            Node(const fuse::vec2<float> & position, const fuse::vec2<float> & scale);
		    // public functions
			inline const int gCost() { return m_cost_g; };
			inline const int hCost() { return m_cost_h; };
			inline const int fCost() { return m_cost_g + m_cost_h; };
			inline const int gCost(int cost) { m_cost_g = cost; return m_cost_g; };
			inline const int hCost(int cost) { m_cost_h = cost; return m_cost_h; };
            // public variables
			Node * parent;
            bool isWalkable;
            fuse::vec2<float> scale;
            fuse::vec2<float> position;
        protected:
            // protected variables
            int m_cost_g;
            int m_cost_h;
            // protected functions
	    };
    }

/**************************************************************************************************/

//#pragma once
//
//class Node
//{
//	ConsoleCanvas::Triangle m_triangle;
//public:
//	bool isWalkable;
//	fuse::Transform transform;
//	fuse::vec4<float> points[4];
//
//	Node(fuse::Transform transform, bool walkable)
//	{
//		// initialize values
//		this->isWalkable = walkable;
//		this->transform.scale = transform.scale;
//		this->transform.rotation = transform.rotation;
//		this->transform.position = transform.position;
//	}
//
//	void Update()
//	{
//		// update points
//		points[0] = fuse::vec4<float>((fuse::vec3<float>(-1.0f, 1.0f, 0) * transform.scale) + transform.position, 1.0f);
//		points[1] = fuse::vec4<float>((fuse::vec3<float>( 1.0f, 1.0f, 0) * transform.scale) + transform.position, 1.0f);
//		points[2] = fuse::vec4<float>((fuse::vec3<float>( 1.0f,-1.0f, 0) * transform.scale) + transform.position, 1.0f);
//		points[3] = fuse::vec4<float>((fuse::vec3<float>(-1.0f,-1.0f, 0) * transform.scale) + transform.position, 1.0f);
//	}
//
//	void Render(ConsoleCanvas * canvas)
//	{
//		// static shared data
//		static fuse::vec4<float> TILE(0.0f, 0.0f, 0.0f, 0.0f);
//		static fuse::vec4<float> LINE(0.5f, 0.5f, 0.5f, 0.7f);
//		static fuse::vec4<float> WALL(1.0f, 1.0f, 1.0f, 1.0f);
//		static ConsoleCanvas::Line node_line = { {}, {}, LINE, LINE };
//		// create node square
//		m_triangle.c1 = isWalkable ? TILE : WALL;
//		m_triangle.c2 = m_triangle.c1;
//		m_triangle.c3 = m_triangle.c2;
//		m_triangle.v1 = points[0];
//		m_triangle.v2 = points[1];
//		m_triangle.v3 = points[2];
//		canvas->render(m_triangle);
//		m_triangle.v1 = points[2];
//		m_triangle.v2 = points[3];
//		m_triangle.v3 = points[0];
//		canvas->render(m_triangle);
//		// create node border
//		node_line.v1 = points[0];
//		node_line.v2 = points[1];
//		canvas->render(node_line);
//		node_line.v1 = points[1];
//		node_line.v2 = points[2];
//		canvas->render(node_line);
//		node_line.v1 = points[2];
//		node_line.v2 = points[3];
//		canvas->render(node_line);
//		node_line.v1 = points[3];
//		node_line.v2 = points[0];
//		canvas->render(node_line);
//	}
//};