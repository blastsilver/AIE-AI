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

#define APP_WIDTH 81
#define APP_HEIGHT 81

void main()
{
	float passedTime = 0;
    fuse::vec2<float> point;
    
    AI::Grid node_grid{ { 20, 20 } };
    ConsoleCanvas canvas{ APP_WIDTH, APP_HEIGHT };
    ScriptUpdateRect script1{ &node_grid };
    ScriptPathFinding script2{ &node_grid };

    script2.m_canvas = &canvas;

    while (true)
    {
        // [PROJECT] Validate cursor position
        point = CalculateCursorPosition();
        if (ValidateCursorPosition(point))
        {
            // [GRAPHICS] clear
            canvas.clear();
            // [PROJECT] update
            script1.Update();
            script2.Update();
            script1.Update(point.x, point.y);
            script2.Update(point.x, point.y);
            // [PROJECT] render
            node_grid.Render(&canvas);
            script1.Render(&canvas);
            script2.Render(&canvas);
            // [GRAPHICS] render
			passedTime += 0.01f;
            canvas.render();
			Sleep(0);
        }
    }
}