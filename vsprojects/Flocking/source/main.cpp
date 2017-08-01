#pragma once
/** Dependencies **********************************************************************************/

	#include "main.h"

	namespace global
	{
		RECT rect;
		POINT point;
	}

	bool ValidateCursorPosition(const fuse::vec2<float> & position)
	{
		// check if out of bounds
		return !(position.x < -1 || position.x > 1 || position.y < -1 || position.y > 1);
	}
	fuse::vec2<float> CalculateCursorPosition()
	{
		// fetch window cursor data
		GetCursorPos(&global::point);
		GetClientRect(GetConsoleWindow(), &global::rect);
		ScreenToClient(GetConsoleWindow(), &global::point);
		// calculate normalized position
		return {
			(float(global::point.x) / (float(global::rect.right - global::rect.left - 1) / 2.0f)) - 1.0f,
			(float(global::point.y) / (float(global::rect.bottom - global::rect.top - 1) / 2.0f)) - 1.0f,
		};
	};

/** Declarations **********************************************************************************/

	void main()
	{
		srand(time(0));
		const int size = 100;
		const float angle = float(2.0f * MATHF_PI) / float(size);
		fuse::vec2<float> pt = CalculateCursorPosition();

		ConsoleCanvas canvas{ 81, 81 };
		std::vector<FlockEntity> entities;

		for (unsigned int i = 0; i < size; i++)
		{
			entities.push_back(FlockEntity{});
			entities[i].range = 3;
			entities[i].scale = 0.001f;
			entities[i].speed = 5.050f;
			entities[i].position.x = (float(rand() % 200) - 100.0f) / 200.0f;
			entities[i].position.y = (float(rand() % 200) - 100.0f) / 200.0f;
			entities[i].cohesionWeight = 1.0f;
			entities[i].alignmentWeight = 1.0f;
			entities[i].separationWeight = 2.0f;
		}
		while (true)
		{
			canvas.clear();

			pt = CalculateCursorPosition();
			if (ValidateCursorPosition(pt))
			{
				for (auto & i : entities)
				{
					fuse::vec2<float> dir = pt - i.position;
					i.Update(dir.x, dir.y);
				}
			}

			for (auto & i : entities)
			{
				i.Update(entities);
				i.Update();
				i.Render(&canvas);
			}

			ConsoleCanvas::Dot dot;
			dot.v1.xy = pt;
			dot.c1 = { 1, 0, 0, 1 };
			canvas.render(dot);

			canvas.render();
		}
	}

/**************************************************************************************************/