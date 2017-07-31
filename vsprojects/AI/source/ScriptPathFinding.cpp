#pragma once
/** Dependencies **********************************************************************************/

    #include "main.h"
    //https://youtu.be/mZfyt03LDH4?t=1047

/** Declarations **********************************************************************************/

    ScriptPathFinding::ScriptPathFinding(AI::Grid * grid) : Script(grid)
    {
        // reset all
        ResetCurrentPath();
    };

    void ScriptPathFinding::Update()
    {

    }

    void ScriptPathFinding::Update(float x, float y)
    {

    }

    void ScriptPathFinding::Render(ConsoleCanvas * canvas)
    {

    }

    int ScriptPathFinding::GetPathDistance(const AI::Node * a, const AI::Node * b)
    {
    }

    void ScriptPathFinding::FindPath(const fuse::vec2<float> & v1, const fuse::vec2<float> & v2)
    {
        // reset all
        ResetCurrentPath();
        // fetch points
        AI::Node * end = m_grid->FetchNode(v1);
        AI::Node * start = m_grid->FetchNode(v2);
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
                m_openList.erase(m_openList.begin() + count);
                // check if finished searching
                if (currentNode == start) return;
                // iterate through current neighbours
                for (auto * i : m_grid->FetchNeighbours(currentNode))
                {
                    // check if valid
                    if (!i->isWalkable || std::find(m_closeList.begin(), m_closeList.end(), i) == m_closeList.end())
                    {
                        continue;
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

/**************************************************************************************************/