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
            void Update(const fuse::vec4<float> & rect);
            void ResetNodes();
            bool ContainsNode(const Node * node);
            Node * SearchNode(const unsigned int index);
            Node * SearchNode(const fuse::vec2<int> & point);
            Node * SearchNode(const fuse::vec2<float> & point);
            std::vector<Node *> SearchNeighbours(const Node * node);
            // public variables
            std::vector<Node> list;
        protected:
            // protected variables
            fuse::vec2<float> m_size;
            fuse::vec2<float> m_scale;
            fuse::vec2<float> m_offset;
            // protected functions
            fuse::vec2<int> WorldToPoint(const fuse::vec2<float> & point);
            bool RectCollision(const fuse::vec4<float> & rect1, const fuse::vec4<float> & rect2);
	    };
    }

/**************************************************************************************************/