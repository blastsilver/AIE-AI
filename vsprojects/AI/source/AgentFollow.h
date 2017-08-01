#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	class AgentFollow : public Script
	{
	public:
		// public defaults
        AgentFollow();
		// public functions
        virtual void Update();
        virtual void Render(ConsoleCanvas * canvas);
        //void SetCurrentNode(Node * node)
    protected:
        // protected variables
        bool m_active;
        // protected functions
	};

/**************************************************************************************************/