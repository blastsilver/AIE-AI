#pragma once

namespace AI
{
	class Grid
	{
	public:
		float grid_NodeRadius;
		std::vector<Node> m_list;
		fuse::vec2<int> grid_WorldSize;

		void Start()
		{

		}

		void Update()
		{
			for (Node & node : m_list)
			{
				node.Update();
			}
		}

		void Render(ConsoleCanvas * canvas)
		{
			for (Node & node : m_list)
			{
				node.Render(canvas);
			}
		}

		void UpdateArea(const fuse::vec4<float> & rect)
		{
			// iterate through nodes
			for (unsigned int i = 0; i < m_list.size(); i++)
			{
				// get node
				Node * node = &m_list[i];
				fuse::vec4<float> nRect{
					node->points[0].x + 1,
					node->points[0].y + 1,
					abs(node->points[0].x - node->points[2].x - 1),
					abs(node->points[0].y - node->points[2].y - 1),
				};
				// check box collisions
				if (CollisionCheck(rect, nRect))
				{
					// update current node
					node->isWalkable = !node->isWalkable;
				}
			}
		}


	protected:

		void CreateGrid()
		{

		}

		bool CollisionCheck(const fuse::vec4<float> & a, const fuse::vec4<float> & b)
		{
			return (a.x < b.x + b.right && a.x + a.right > b.x && a.y < b.y + b.bottom && a.bottom + a.y > b.y);
		}
	};
}