/** Dependencies **********************************************************************************/

	#include "main.h"
	#include <string>

/** Declarations **********************************************************************************/

	// public defaults
	ScriptNodeRemover::ScriptNodeRemover(AI::Grid * grid)
	{
		// initialize values
		m_grid = grid;
		m_line.c1 = { 1.0f, 0.0f, 0.0f, 1.0f };
		m_line.c2 = { 0.0f, 0.0f, 1.0f, 1.0f };
		m_keyPress = false;
		m_mouseClick = false;
		m_mouseClick1 = false;
		m_mouseClick2 = false;
	}

	// public functions
	void ScriptNodeRemover::Update()
	{
		POINT pt;
		RECT rect;
		// get cursor pos
		GetCursorPos(&pt);
		ScreenToClient(GetConsoleWindow(), &pt);
		GetClientRect(GetConsoleWindow(), &rect);
		// check mouse cursor
		if (ValidateCursorPos(&pt, &rect))
		{
			// check mouse state 1
			if (m_mouseClick1)
			{
				m_pos2 = CalculateCursorPos(&pt, &rect);
				// check mouse state 2
				if (m_mouseClick2)
				{
					// reset mouse states
					m_mouseClick1 = false;
					m_mouseClick2 = false;
				}
				// check for keyboard state
				if ((GetKeyState(0x41) & 0x100) != 0)
				{
					if (!m_keyPress)
					{
						// set key press
						m_keyPress = true;
						m_mouseClick1 = false;
						m_mouseClick2 = false;
						// update nodes in area
						m_grid->UpdateArea(fuse::vec4<float>{
							(m_pos1.x < m_pos2.x ? m_pos1.x : m_pos2.x) + 1,
							(m_pos1.y < m_pos2.y ? m_pos1.y : m_pos2.y) + 1,
							abs(m_pos2.x - m_pos1.x - 1),
							abs(m_pos2.y - m_pos1.y - 1),
						});
					}
				}
				else m_keyPress = false;
			}
			// check for mouse press
			if (!m_mouseClick && (GetKeyState(VK_RBUTTON) & 0x100) != 0)
			{
				// set mouse click
				m_mouseClick = true;
				// check 1st mouse click
				if (m_mouseClick1 == false)
				{
					// update position
					m_pos1 = CalculateCursorPos(&pt, &rect);
					m_pos2 = m_pos1;
					// set boolean
					m_mouseClick1 = true;
				}
				else if (m_mouseClick2 == false)
				{
					// update position
					m_pos2 = CalculateCursorPos(&pt, &rect);
					// set boolean
					m_mouseClick2 = true;
				}
			}
			// check for mouse release
			else if (m_mouseClick && !(GetKeyState(VK_RBUTTON) & 0x100) != 0) m_mouseClick = false;
		}
	}

	void ScriptNodeRemover::Render(ConsoleCanvas * canvas)
	{
		// check mouse state
		if (m_mouseClick1)
		{
			// draw lines
			m_line.v1.xy = m_pos1;
			m_line.v2.xy = { m_pos2.x, m_pos1.y };
			canvas->render(m_line);
			m_line.v2.xy = m_pos2;
			m_line.v1.xy = { m_pos2.x, m_pos1.y };
			canvas->render(m_line);
			m_line.v1.xy = m_pos2;
			m_line.v2.xy = { m_pos1.x, m_pos2.y };
			canvas->render(m_line);
			m_line.v2.xy = m_pos1;
			m_line.v1.xy = { m_pos1.x, m_pos2.y };
			canvas->render(m_line);
			m_line.v1.xy = m_pos1;
			m_line.v2.xy = m_pos2;
			canvas->render(m_line);
		}
	}

	// protected functions
	bool ScriptNodeRemover::ValidateCursorPos(POINT * pt, RECT * rect)
	{
		// vertical check
		if (pt->y < 0 || pt->y > (rect->bottom - rect->top - 1))
			return false;
		// horizontal check
		if (pt->x < 0 || pt->x > (rect->right - rect->left - 1))
			return false;
		// return as successfull
		return true;
	}

	fuse::vec2<float> ScriptNodeRemover::CalculateCursorPos(POINT * pt, RECT * rect)
	{
		// calculate normalized cursor position
		return {
			(float(pt->x) / ((float(rect->right - rect->left - 1) - 0.5f) / 2.0f)) - 1,
			(float(pt->y) / ((float(rect->bottom - rect->top - 1) - 0.5f) / 2.0f)) - 1,
		};
	}

/**************************************************************************************************/