/** Dependencies **********************************************************************************/

    #include "main.h"

/** Declarations **********************************************************************************/

    ScriptUpdateRect::ScriptUpdateRect(AI::Grid * grid) : Script(grid)
    {
        // initialize values
        m_toggle = false;
        m_mPress = false;
    };

    void ScriptUpdateRect::Update()
    {
        // check key press on toggle
        if (m_toggle && KeyPress(VK_LBUTTON))
        {
            // update values
            m_toggle = false;
            // update node grid
            m_grid->Update({
                m_position1.x < m_position2.x ? m_position1.x : m_position2.x,
                m_position1.y < m_position2.y ? m_position1.y : m_position2.y,
                abs(m_position2.x - m_position1.x),
                abs(m_position2.y - m_position1.y),
            });
        }
        // check mouse state
        if (KeyPress(VK_RBUTTON))
        {
            if (!m_mPress)
            {
                // update values
                m_mPress = true;
                m_toggle = !m_toggle;
            }
        }
        else m_mPress = false;
    };

    void ScriptUpdateRect::Update(float x, float y)
    {
        if (m_toggle)
        {
            // set position 2
            m_position2.x = x;
            m_position2.y = y;
        }
        else
        {
            // set position 1
            m_position1.x = x;
            m_position1.y = y;
        }
    };
    
    void ScriptUpdateRect::Render(ConsoleCanvas * canvas)
    {
        if (m_toggle)
        {
            ConsoleCanvas::Line line;
            // set colours
            line.c1 = { 1, 0, 0, 1 };
            line.c2 = { 0, 0, 1, 1 };
            // draw line [top]
            line.v1 = { m_position1, 0, 0 };
            line.v2 = { m_position1.x, m_position2.y, 0, 0 };
            canvas->render(line);
            // draw line [left]
            line.v1 = { m_position1.x, m_position2.y, 0, 0 };
            line.v2 = { m_position2, 0, 0 };
            canvas->render(line);
            // draw line [right]
            line.v1 = { m_position2, 0, 0 };
            line.v2 = { m_position2.x, m_position1.y, 0, 0 };
            canvas->render(line);
            // draw line [bottom]
            line.v1 = { m_position2.x, m_position1.y, 0, 0 };
            line.v2 = { m_position1, 0, 0 };
            canvas->render(line);
            // draw line [diagonal]
            line.v1 = { m_position1, 0, 0 };
            line.v2 = { m_position2, 0, 0 };
            canvas->render(line);
        }
    };

/**************************************************************************************************/