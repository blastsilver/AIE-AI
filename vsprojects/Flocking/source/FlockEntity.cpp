#pragma once
/** Dependencies **********************************************************************************/

	#include "main.h"

/** Declarations **********************************************************************************/

	FlockEntity::FlockEntity()
	{
		// initialize values
		this->speed = 1;
		this->range = 5;
		this->position = { 0, 0 };
		this->direction = { 0, -1 };
		this->cohesionWeight = 1;
		this->alignmentWeight = 1;
		this->separationWeight = 1;
	};

	void FlockEntity::Update()
	{
		// update position
		position.x += direction.x * speed;
		position.y += direction.y * speed;
	};

	void FlockEntity::Update(float x, float y)
	{
		// update direction
		fuse::vec2<float> n = { x, y };
		//NORMALIZE(n);
		direction.x += n.x;
		direction.y += n.y;
		NORMALIZE(direction);
	};

	void FlockEntity::Render(ConsoleCanvas * canvas)
	{
        // update dot
        DOT.v1.xy = position;		
        DOT.c1 = { 1, 1, 1, 1 };
		// render the dot
		canvas->render(DOT);
	};

	void FlockEntity::Update(std::vector<FlockEntity> & agents)
	{
		fuse::vec2<float> cohesion = COMPUTE_COHESION(agents);
		fuse::vec2<float> alignment = COMPUTE_ALIGNMENT(agents);
		fuse::vec2<float> separation = COMPUTE_SEPARATION(agents);

		direction.x += alignment.x * alignmentWeight + cohesion.x * cohesionWeight + separation.x * separationWeight;
		direction.y += alignment.y * alignmentWeight + cohesion.y * cohesionWeight + separation.y * separationWeight;

		NORMALIZE(direction);

        // update direction
        if (LENGTH(position + fuse::vec2<float>{ direction.x * speed, direction.y * speed }) > 1.0f)
        {
            direction.x = -direction.x;
            direction.y = -direction.y;
        }
        //if ((position.x + (direction.x * speed)) < -0.8f || (position.x + (direction.x * speed)) > 0.8f) direction.x = -direction.x;
        //else if ((position.y + (direction.y * speed)) < -0.8f || (position.y + (direction.y * speed)) > 0.8f) direction.y = -direction.y;
	};
	
	void FlockEntity::NORMALIZE(fuse::vec2<float> & a)
	{
		// normalize vector
		const float length = LENGTH(a);
        if (length != 0.0f)
        {
		    a.x /= length;
		    a.y /= length;
        }
        else
        {
            a.x = 0;
            a.y = 0;
        }
	}

	void FlockEntity::ROTATE(fuse::vec4<float> & vector, const float angle)
	{
		// calculate new vector
		vector.xy = {
			vector.x * cos(angle) + vector.y * -sin(angle),
			vector.x * sin(angle) + vector.y * cos(angle),
		};
	};

	float FlockEntity::LENGTH(fuse::vec2<float> & a)
	{
        const float dot = PRODUCT_DOT(a, a);
		// calculate vector lenght
		return dot == 0.0f ? 0.0f : sqrtf(dot);
	};

	float FlockEntity::PRODUCT_DOT(fuse::vec2<float> & a, fuse::vec2<float> & b)
	{
		// calculate dot product
		return a.x * b.x + a.y * b.y;
	};

	fuse::vec2<float> FlockEntity::COMPUTE_COHESION(std::vector<FlockEntity> & agents)
	{
		float count = 0.0f;
		fuse::vec2<float> point;
		// iterate through agents
		for (auto & agent : agents)
		{
			// check if object
			if (&agent != this)
			{
				// check direction
				fuse::vec2<float> dir = agent.position - position;
				// check agent distance
				if (LENGTH(dir) < range)
				{
					count++;
					point.x += agent.position.x;
					point.y += agent.position.y;
				}
			}
		}
		// check if empty
		if (count == 0) return point;
		// update point
		point.x /= count;
		point.y /= count;
		point = { point.x - position.x, point.y - position.y };
		NORMALIZE(point);
		// return point
		return point;
	};

	fuse::vec2<float> FlockEntity::COMPUTE_ALIGNMENT(std::vector<FlockEntity> & agents)
	{
		float count = 0.0f;
		fuse::vec2<float> point;
		// iterate through agents
		for (auto & agent : agents)
		{
			// check if object
			if (&agent != this)
			{
				// check direction
				fuse::vec2<float> dir = agent.position - position;
				// check agent distance
				if (LENGTH(dir) < range)
				{
					count++;
					point.x += agent.direction.x;
					point.y += agent.direction.y;
				}
			}
		}
		// check if empty
		if (count == 0) return point;
		// update point
		point.x /= count;
		point.y /= count;
		NORMALIZE(point);
		// return point
		return point;
	};

	fuse::vec2<float> FlockEntity::COMPUTE_SEPARATION(std::vector<FlockEntity> & agents)
	{
		float count = 0.0f;
		fuse::vec2<float> point;
		// iterate through agents
		for (auto & agent : agents)
		{
			// check if object
			if (&agent != this)
			{
				// check direction
				fuse::vec2<float> dir = agent.position - position;
				// check agent distance
				if (LENGTH(dir) < range)
				{
					count++;
					point.x += agent.position.x - position.x;
					point.y += agent.position.y - position.y;
				}
			}
		}
		// check if empty
		if (count == 0) return point;
		// update point
		point.x /= -1;
		point.y /= -1;
		NORMALIZE(point);
		// return point
		return point;
	};

/**************************************************************************************************/