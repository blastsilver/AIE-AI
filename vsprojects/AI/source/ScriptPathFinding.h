#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	class ScriptPathFinding : public Script
	{
	public:
		// public defaults
        ScriptPathFinding(AI::Grid * grid);
		// public functions
        virtual void Update();
        virtual void Update(float x, float y);
        virtual void Render(ConsoleCanvas * canvas);
    protected:
        // protected variables
        bool m_kPress;
        bool m_pathFound;
        ConsoleCanvas::Line m_line;
        ConsoleCanvas::Text m_text;
        std::vector<AI::Node*> m_openList;
        std::vector<AI::Node*> m_closeList;
        // protected functions
        int GetPathDistance(const AI::Node * a, const AI::Node * b);
        void FindPath(const fuse::vec2<float> & v1, const fuse::vec2<float> & v2);
        void ResetCurrentPath();
        void RENDER_NodeList(const std::vector<AI::Node*> & data, ConsoleCanvas * canvas);
	};

/**************************************************************************************************/