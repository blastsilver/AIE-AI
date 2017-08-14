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
			inline const float gCost() { return m_cost_g; };
			inline const float hCost() { return m_cost_h; };
			inline const float fCost() { return m_cost_g + m_cost_h; };
			inline const float gCost(float cost) { m_cost_g = cost; return m_cost_g; };
			inline const float hCost(float cost) { m_cost_h = cost; return m_cost_h; };
            // public variables
			Node * parent;
            bool isWalkable;
            fuse::vec2<float> scale;
            fuse::vec2<float> position;
        protected:
            // protected variables
            float m_cost_g;
            float m_cost_h;
            // protected functions
	    };
    }

/**************************************************************************************************/