#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	class ScriptPathFinding : Script
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
        bool m_pathFound;
        std::vector<AI::Node*> m_openList;
        std::vector<AI::Node*> m_closeList;
        // protected functions
        int GetPathDistance(const AI::Node * a, const AI::Node * b);
        void FindPath(const fuse::vec2<float> & v1, const fuse::vec2<float> & v2);
        void ResetCurrentPath();
	};

/**************************************************************************************************/