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

    fuse::vec3<float> RotatePoint(const fuse::vec3<float> & vector, const float angle)
    {
        // calculate new vector
        return {
            vector.x * cos(angle) + vector.y * -sin(angle),
            vector.x * sin(angle) + vector.y * cos(angle),
            vector.z,
        };
    };

/** Declarations **********************************************************************************/

	void main()
	{
        // [flocking] variables
		srand((unsigned int)time(time_t(0)));
		const int flockSize = 500;
		fuse::vec2<float> pt = CalculateCursorPosition();
		std::vector<FlockEntity> flockGroup;
        // [flocking] creation
        for (size_t i = 0; i < flockSize; i++)
        {
            flockGroup.push_back(FlockEntity{});
            flockGroup[i].range = 0.07f;
            flockGroup[i].speed = 0.02f;
            flockGroup[i].position.x = (float(rand() % 200) - 100.0f) / 200.0f;
            flockGroup[i].position.y = (float(rand() % 200) - 100.0f) / 200.0f;
            flockGroup[i].cohesionWeight = 0.01f;
            flockGroup[i].alignmentWeight = 0.2f;
            flockGroup[i].separationWeight = 1.0f;
        }
        // [bonus star] variables
        float timer = 0;
        const int starSize = 5;
		const float starAngle = float(2.0f * MATHF_PI) / float(starSize);
        ConsoleCanvas::Triangle starTriangle;
        starTriangle.c1 = { 1, 0, 0, 1.0f };
        starTriangle.c2 = { 0, 0, 1, 1.0f };
        starTriangle.c3 = { 0, 1, 0, 1.0f }; 
        // console canvas renderer
		ConsoleCanvas canvas{ 81, 81 };
        // while running
		while (true)
		{
            // clear console
			canvas.clear();
            // [bonus star] update & render
            for (int i = 0; i < starSize; i++)
            {
                // render star shape
                starTriangle.v1.xyz = RotatePoint({ -0.5f, 0.0f, 1.00f }, starAngle * float(i) + timer);
                starTriangle.v2.xyz = RotatePoint({  0.0f, 1.0f, 2.00f }, starAngle * float(i) + timer);
                starTriangle.v3.xyz = RotatePoint({  0.5f, 0.0f, 2.00f }, starAngle * float(i) + timer);
                canvas.render(starTriangle);
            }
            timer += 0.1f;

            // [flocking] update & render
			pt = CalculateCursorPosition();
			for (auto & i : flockGroup)
			{
                // move to cursor
                if (ValidateCursorPosition(pt))
                {
                    fuse::vec2<float> dir = pt - i.position;
                    i.Update(dir.x, dir.y);
                }
                // update flocking ai
				i.Update(flockGroup);
				i.Update();
				i.Render(&canvas);
			}

            // draw cursor
			ConsoleCanvas::Dot dot;
			dot.v1.xy = pt;
			dot.c1 = { 1, 0, 0, 1 };
			canvas.render(dot);

            // render console
			canvas.render();
            Sleep(20);
		}
	}

/**************************************************************************************************/