#pragma once
/** Dependencies **********************************************************************************/

    #include "main.h"

    fuse::vec2<float> Lerp(const fuse::vec2<float> & a, const fuse::vec2<float> & b, float t)
    {
        return{
            a.x + (b.x - a.x) * t,
            a.y + (b.y - a.y) * t,
        };
    };

/** Declarations **********************************************************************************/

    AgentFollow::AgentFollow() : Script(NULL)
    {
        this->m_active = false;
        this->m_count = 0;
        this->parent = nullptr;
    };

    void AgentFollow::SetState(bool active)
    {
        m_active = active;
    }

    void AgentFollow::Update()
    {
        if (m_active && parent != nullptr)
        {
            position = Lerp(position, parent->position, m_count);


            // update data
            if (m_count > 1 || (position.x == parent->position.x && position.y == parent->position.y))
            { m_count = 0; parent = parent->parent; }
            else m_count += 0.1f;
        }
    };

    void AgentFollow::Render(ConsoleCanvas * canvas)
    {
        if (m_active && parent != nullptr)
        {
            scale.x = parent->scale.x;
            scale.y = parent->scale.y;
        }
        TRIANGLE.v1.xy = { position.x, position.y, };
        TRIANGLE.v2.xy = { position.x + scale.x / 2, position.y, };
        TRIANGLE.v3.xy = { position.x + scale.x / 4, position.y + scale.y / 2, };
        TRIANGLE.c1 = { 1, 0, 0, 1 };
        TRIANGLE.c2 = { 2, 1, 0, 1 };
        TRIANGLE.c3 = { 2, 0, 1, 1 };
        canvas->render(TRIANGLE);
    };

/**************************************************************************************************/