#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	class AgentFollow : public Script
	{
	public:
		// public defaults
        AgentFollow();
		// public functions
        void SetState(bool active);
        virtual void Update();
        virtual void Render(ConsoleCanvas * canvas);
        // public variables
        AI::Node * parent;
        fuse::vec2<float> scale;
        fuse::vec2<float> position;
    protected:
        // protected variables
        bool m_active;
        float m_count;
        // protected functions
	};

/**************************************************************************************************/