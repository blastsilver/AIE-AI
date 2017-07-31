#pragma once
/** Dependencies **********************************************************************************/

    #include "main.h"

/** Declarations **********************************************************************************/

    AI::Node::Node(const fuse::vec2<float> & position, const fuse::vec2<float> & scale)
    {
        // initialize values
        this->isWalkable = true;
        this->scale.x = scale.x;
        this->scale.y = scale.y;
        this->position.x = position.x;
        this->position.y = position.y;
    }

/**************************************************************************************************/