#pragma once

class Node
{
public:
	bool isWalkable;
	fuse::Transform transform;
	fuse::vec4<float> points[4];

	Node(fuse::Transform transform, bool walkable)
	{
		// initialize values
		this->isWalkable = walkable;
		this->transform.scale = transform.scale;
		this->transform.rotation = transform.rotation;
		this->transform.position = transform.position;
	}

	void Update()
	{
		// update points
		points[0] = fuse::vec4<float>((fuse::vec3<float>(-0.75f, 0.75f, 0) * transform.scale) + transform.position, 1.0f);
		points[1] = fuse::vec4<float>((fuse::vec3<float>( 0.75f, 0.75f, 0) * transform.scale) + transform.position, 1.0f);
		points[2] = fuse::vec4<float>((fuse::vec3<float>( 0.75f,-0.75f, 0) * transform.scale) + transform.position, 1.0f);
		points[3] = fuse::vec4<float>((fuse::vec3<float>(-0.75f,-0.75f, 0) * transform.scale) + transform.position, 1.0f);
	}

	void Render(ConsoleCanvas * canvas)
	{
		// static shared data
		static fuse::vec4<float> WALL(0.7f, 0.7f, 0.7f, 1.0f);
		static fuse::vec4<float> LINE(0.5f, 0.5f, 0.5f, 1.0f);
		static fuse::vec4<float> TILE(1.0f, 1.0f, 1.0f, 1.0f);
		static ConsoleCanvas::Line node_line = { {}, {}, LINE, LINE };
		static ConsoleCanvas::Triangle node_triangle = { {}, {}, {}, TILE, TILE, TILE };
		// create node square
		node_triangle.v1 = points[0];
		node_triangle.v2 = points[1];
		node_triangle.v3 = points[2];
		canvas->render(node_triangle);
		node_triangle.v1 = points[2];
		node_triangle.v2 = points[3];
		node_triangle.v3 = points[0];
		canvas->render(node_triangle);
		// create node border
		node_line.v1 = points[0];
		node_line.v2 = points[1];
		canvas->render(node_line);
		node_line.v1 = points[1];
		node_line.v2 = points[2];
		canvas->render(node_line);
		node_line.v1 = points[2];
		node_line.v2 = points[3];
		canvas->render(node_line);
		node_line.v1 = points[3];
		node_line.v2 = points[0];
		canvas->render(node_line);
	}
};