#pragma once
/** Dependencies **********************************************************************************/

    #include "main.h"

/** Declarations **********************************************************************************/

    ScriptPathFinding::ScriptPathFinding(AI::Grid * grid) : Script(grid)
    {
        // reset all
        ResetCurrentPath();
    };

    void ScriptPathFinding::Update()
    {
        if (KeyPress(VK_RETURN))
        {
            if (!m_kPress)
            {
                m_kPress = true;
                FindPath({ -1, -1 }, { 1, 1 });
            }
        }
        else m_kPress = false;
        
        nodeFollow.SetState(m_pathFound);
        nodeFollow.Update();
    }

    void ScriptPathFinding::Update(float x, float y)
    {
    }

    void ScriptPathFinding::Render(ConsoleCanvas * canvas)
    {
        if (m_pathFound)
        {
		    LINE.c1 = { 0, 1, 0, 1 };
            LINE.c2 = { 0, 0, 1, 1 };
            TEXT.c1 = { 1, 0, 0, 1 };
            RENDER_NodeList(m_openList, canvas);
            LINE.c1 = { 1, 0, 0, 1 };
            RENDER_NodeList(m_closeList, canvas);

            nodeFollow.Render(canvas);
        }
    }

    int ScriptPathFinding::GetPathDistance(const AI::Node * a, const AI::Node * b)
    {
		float dstX = abs(a->position.x - b->position.x);
		float dstY = abs(a->position.y - b->position.y);

		if (dstX > dstY)
			return int(14 * dstY + 10 * (dstX - dstY));
		return int(14 * dstX + 10 * (dstY - dstX));
    }

    void ScriptPathFinding::FindPath(const fuse::vec2<float> & v1, const fuse::vec2<float> & v2)
    {
        // reset all
        ResetCurrentPath();
        // fetch points
        AI::Node * end = m_grid->SearchNode(v1);
        AI::Node * start = m_grid->SearchNode(v2);
        // check if found
        if (start != 0 && end != 0)
        {
            // add start to open list
            m_openList.push_back(start);
            // check if open list has nodes
            while (m_openList.size() > 0)
            {
                int count = 0;
                AI::Node * currentNode = nullptr;
                // iterate through open list
                for (auto * i : m_openList)
                {
                    // find cheapest node
                    if (currentNode == nullptr || i->fCost() <= currentNode->fCost() && i->hCost() < currentNode->hCost())
                    {
                        // update current node
                        currentNode = i; count++;
                    }
                }
                // swap values between lists
                m_closeList.push_back(currentNode);
                m_openList.erase(std::find(m_openList.begin(), m_openList.end(), currentNode));
                // check if finished searching
				if (currentNode == end)
				{
                    nodeFollow.position = end->position;
                    nodeFollow.parent = end;
					m_pathFound = true;
					return;
				}
                // iterate through current neighbours
                for (auto * i : m_grid->SearchNeighbours(currentNode))
                {
                    // check if valid
                    if (!i->isWalkable || std::find(m_closeList.begin(), m_closeList.end(), i) != m_closeList.end())
                    {
                        continue;
                    }

					int costToNeighbour = currentNode->gCost() + GetPathDistance(currentNode, i);
					if (costToNeighbour < i->gCost() || std::find(m_openList.begin(), m_openList.end(), i) == m_openList.end())
					{
						i->gCost(costToNeighbour);
						i->hCost(GetPathDistance(i, end));
						i->parent = currentNode;

						if (std::find(m_openList.begin(), m_openList.end(), i) == m_openList.end())
						{
							m_openList.push_back(i);
						}
					}
                }
            }
        }
    }

    void ScriptPathFinding::ResetCurrentPath()
    {
        // reset values
        m_openList.clear();
        m_closeList.clear();
        m_pathFound = false;
    }

    void ScriptPathFinding::RENDER_NodeList(const std::vector<AI::Node*> & data, ConsoleCanvas * canvas)
    {
        for (auto * i : data)
        {
            if (i->parent != nullptr)
            {
                std::string str = std::to_string(i->fCost());
                // render line
                LINE.v1.xy = i->position + fuse::vec2<float>{ i->scale.x / 2, i->scale.y / 2 };
                LINE.v2.xy = i->parent->position.xy + fuse::vec2<float>{ i->scale.x / 2, i->scale.y / 2 };
                canvas->render(LINE);
                // render text
                TEXT.v1.xy = i->position + fuse::vec2<float>{ i->scale.x / 2, i->scale.y / 3 };
                TEXT.cstring = (char*)(str.c_str());
                canvas->render(TEXT);
            }
        }
    }

/**************************************************************************************************/