#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	class ScriptUpdateRect : Script
	{
	public:
		// public defaults
        ScriptUpdateRect(AI::Grid * grid);
		// public functions
        virtual void Update();
        virtual void Update(float x, float y);
        virtual void Render(ConsoleCanvas * canvas);
    protected:
        // protected variables
        bool m_toggle;
        bool m_mPress;
        fuse::vec2<float> m_position1;
        fuse::vec2<float> m_position2;
        // protected functions
	};

/**************************************************************************************************/