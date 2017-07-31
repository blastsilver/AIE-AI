#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

    namespace AI
    {
	    class Grid
	    {
	    public:
		    // public defaults
            Grid(const fuse::vec2<int> & size);
		    // public functions
            void Render(ConsoleCanvas * canvas);
            void UpdateArea(const fuse::vec4<float> & rect);
            Node * FetchNode(const fuse::vec2<float> & point);
            std::vector<Node *> FetchNeighbours(const Node * node);
            // public variables
            std::vector<Node> list;
        protected:
            // protected variables
            fuse::vec2<int> m_size;
            fuse::vec2<float> m_scale;
            fuse::vec2<float> m_offset;
            // protected functions
            bool RectCollision(const fuse::vec4<float> & rect1, const fuse::vec4<float> & rect2);
	    };
    }

/**************************************************************************************************/