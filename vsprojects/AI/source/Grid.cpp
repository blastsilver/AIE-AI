#pragma once
/** Dependencies **********************************************************************************/

    #include "main.h"

/** Declarations **********************************************************************************/

    AI::Grid::Grid(const fuse::vec2<int>& size)
    {
        // initialize values
        m_size = size;
        m_scale = { 2.0f / float(size.x), 2.0f / float(size.y), };
        m_offset = { float(size.x) / 2.0f, float(size.y) / 2.0f, };
        // create new array list
        for (int y = 0; y < size.y; y++)
        {
            for (int x = 0; x < size.x; x++)
            {
                this->list.push_back(Node{
                    { (float(x) - m_offset.x) * m_scale.x, (float(y) - m_offset.y) * m_scale.y },
                    { m_scale.x, m_scale.y },
                });
            }
        }
    }

    void AI::Grid::Render(ConsoleCanvas * canvas)
    {
        fuse::vec4<float> nodeRGB;
        fuse::vec4<float> lineRGB{ 0.5f, 0.0f, 0.5f, 1.0f };
        ConsoleCanvas::Line line{ {}, {}, lineRGB, lineRGB };
        ConsoleCanvas::Triangle triangle{};
        // iterate through node list
        for (auto &i : list)
        {
            // check if walkable
            if (i.isWalkable) nodeRGB = { 0.5f, 0.5f, 0.0f, 1.0f };
            else              nodeRGB = { 0.5f, 0.0f, 0.0f, 1.0f };
            // update colours
            triangle.c1 = nodeRGB;
            triangle.c2 = nodeRGB;
            triangle.c3 = nodeRGB;
            // top-left triangle/lines
            triangle.v1.xy = { i.position.x, i.position.y };
            triangle.v2.xy = { i.position.x + m_scale.x, i.position.y };
            triangle.v3.xy = { i.position.x, i.position.y + m_scale.y };
            canvas->render(triangle);
            line.v1 = triangle.v1;
            line.v2 = triangle.v2;
            canvas->render(line);
            line.v1 = triangle.v1;
            line.v2 = triangle.v3;
            canvas->render(line);
            // bottom-right triangle/lines
            triangle.v1.xy = { i.position.x, i.position.y + m_scale.y };
            triangle.v2.xy = { i.position.x + m_scale.x, i.position.y, };
            triangle.v3.xy = { i.position.x + m_scale.x, i.position.y + m_scale.y, };
            canvas->render(triangle);
            line.v1 = triangle.v3;
            line.v2 = triangle.v1;
            canvas->render(line);
            line.v1 = triangle.v3;
            line.v2 = triangle.v2;
            canvas->render(line);
        }
        int zz = 0;
    }

    void AI::Grid::UpdateArea(const fuse::vec4<float> & rect)
    {
        // iterate through node list
        for (auto &i : list)
        {
            // check collision
            if (RectCollision({ i.position.x, i.position.y, m_scale.x, m_scale.y }, rect))
            {
                // toggle state
                i.isWalkable = !i.isWalkable;
            }
        }
    }

    AI::Node * AI::Grid::FetchNode(const fuse::vec2<float> & point)
    {
        // iterate through node list
        for (auto &i : list)
        {
			float sizeX = i.scale.x / 2;
			float sizeY = i.scale.y / 2;
			float posX = point.x + (point.x > 0 ? -sizeX : sizeX) / 2.0f;
			float posY = point.y + (point.y > 0 ? -sizeY : sizeY) / 2.0f;

            // check collision
            if (RectCollision({ posX, posY, sizeX, sizeY }, { i.position, i.scale }))
            {
                // return address
                return &i;
            }
        }
        // failed to fetch
        return 0;
    }

    std::vector<AI::Node *> AI::Grid::FetchNeighbours(const AI::Node * node)
    {
        std::vector<Node *> neighbours;
        for (float y = -1; y < 2; y++)
        {
            for (float x = -1; x < 2; x++)
            {
                if (x == 0 && y == 0) continue;
                Node * temp = FetchNode({
                    node->position.x + (node->scale.x * x),
                    node->position.y + (node->scale.y * y),
                });
                if (temp != NULL) neighbours.push_back(temp);
            }
        }
		return neighbours;
    }

    bool AI::Grid::RectCollision(const fuse::vec4<float> & rect1, const fuse::vec4<float> & rect2)
    {
        // AABB - https://developer.mozilla.org/en-US/docs/Games/Techniques/2D_collision_detection
        return (rect1.x < rect2.x + rect2.right && rect1.x + rect1.right > rect2.x && rect1.y < rect2.y + rect2.bottom && rect1.bottom + rect1.y > rect2.y);
    }

/**************************************************************************************************/