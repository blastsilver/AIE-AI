#pragma once
/** Dependencies **********************************************************************************/

    #include "main.h"

/** Declarations **********************************************************************************/

    AI::Node::Node(const fuse::vec2<float> & position, const fuse::vec2<float> & scale)
    {
        // initialize values
		this->parent = nullptr;
        this->scale.x = scale.x;
        this->scale.y = scale.y;
		this->m_cost_g = 0;
		this->m_cost_h = 0;
        this->isWalkable = true;
        this->position.x = position.x;
        this->position.y = position.y;
    }

/**************************************************************************************************/