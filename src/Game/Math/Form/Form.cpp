#include "Game/Math/Form/Form.h"

#include <math.h>

namespace form
{
	bool isCircleCollidingCircle(Circle c1, Circle c2)
	{
		float dx = static_cast<float>(fabs(c1.pos.x - c2.pos.x));
		float dy = static_cast<float>(fabs(c1.pos.y - c2.pos.y));

		return ((dx <= c1.radius && dy <= c1.radius)
			|| dx <= c2.radius && dy <= c2.radius);
	}

	bool isPointCollidingRect(Vector2 p, Rectangle rect)
	{
		return p.x <= rect.pos.x + rect.width && p.x >= rect.pos.x &&
			p.y <= rect.pos.y + rect.height && p.y >= rect.pos.y;
	}

	Vector2 centerToTopLeft(Rectangle rect)
	{
		Vector2 topLeftPos = {};
		topLeftPos.x = rect.pos.x - rect.width / 2;
		topLeftPos.y = rect.pos.y - rect.height / 2;

		return topLeftPos;
	}

	bool isRectColCircle(Rectangle rect, Circle circ)
	{
		Vector2 closestPoint = {};

		if (circ.pos.x < rect.pos.x - rect.width/2)
		{
			closestPoint.x = rect.pos.x - rect.width/2;
		}
		else if (circ.pos.x > rect.pos.x + rect.width/2)
		{
			closestPoint.x = rect.pos.x + rect.width / 2;
		}
		else
		{
			closestPoint.x = circ.pos.x;
		}

		if (circ.pos.y <= rect.pos.y-rect.height/2)
		{
			closestPoint.y = rect.pos.y - rect.height / 2;
		}
		else if (circ.pos.y >= rect.pos.y + rect.height/2)
		{
			closestPoint.y = rect.pos.y + rect.height / 2;
		}
		else
		{
			closestPoint.y = circ.pos.y;
		}

		return (closestPoint.x - circ.pos.x) * (closestPoint.x - circ.pos.x) + (closestPoint.y - circ.pos.y) * (closestPoint.y - circ.pos.y) <= (circ.radius * circ.radius);
	}
}