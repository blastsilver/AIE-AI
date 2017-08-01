#pragma once
/** Dependencies **********************************************************************************/

	#include "main.h"

/** Declarations **********************************************************************************/

	FlockEntity::FlockEntity()
	{
		// initialize values
		this->scale = 1;
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
		position.x += direction.x * speed * scale;
		position.y += direction.y * speed * scale;
	};

	void FlockEntity::Update(float x, float y)
	{
		// update direction
		fuse::vec2<float> n = { x, y };
		NORMALIZE(n);
		direction.x += n.x;
		direction.y += n.y;
		NORMALIZE(direction);
	};

	void FlockEntity::Render(ConsoleCanvas * canvas)
	{
		// update triangle
		TRIANGLE.v1.xyz = { position.x - (scale / 2.0f), position.y + (scale / 2.0f), 0 };
		TRIANGLE.v2.xyz = { TRIANGLE.v1.x + scale, TRIANGLE.v1.y, 1 };
		TRIANGLE.v3.xyz = { position.x, TRIANGLE.v1.y - scale, 0 };
		TRIANGLE.c1 = { 1, 0, 0, 1 };
		TRIANGLE.c2 = { 0, 1, 0, 1 };
		TRIANGLE.c3 = { 0, 0, 1, 1 };
		// update transform
		//ROTATE(TRIANGLE.v1, rotation);
		//ROTATE(TRIANGLE.v2, rotation);
		//ROTATE(TRIANGLE.v3, rotation);
		// render the triangle
		canvas->render(TRIANGLE);
	};

	void FlockEntity::Update(std::vector<FlockEntity> & agents)
	{
		fuse::vec2<float> cohesion = COMPUTE_COHESION(agents);
		fuse::vec2<float> alignment = COMPUTE_ALIGNMENT(agents);
		fuse::vec2<float> separation = COMPUTE_SEPARATION(agents);

		direction.x += alignment.x * alignmentWeight + cohesion.x * cohesionWeight + separation.x * separationWeight;
		direction.y += alignment.y * alignmentWeight + cohesion.y * cohesionWeight + separation.y * separationWeight;

		NORMALIZE(direction);
	};
	
	void FlockEntity::NORMALIZE(fuse::vec2<float> & a)
	{
		// normalize vector
		const float length = LENGTH(a);
		a.x /= length;
		a.y /= length;
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
		// calculate vector lenght
		return sqrtf(PRODUCT_DOT(a, a));
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
					point.x += agent.direction.x - position.x;
					point.y += agent.direction.y - position.y;
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