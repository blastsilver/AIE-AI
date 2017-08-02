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