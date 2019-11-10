#include "Circle.h"

//Circle Constructor 
Circle::Circle(float r, float g, float b, float x, float y, float rad) : Shape(r, g, b, x, y)
{
	radius = rad;
}

void Circle::move_item_x(void)
{
	if (move_right == true)
	{
		if (pos[0] < 1 - radius)
		{
			pos[0] += speed[0];
		}
		else
		{
			move_right = false;
			random_color();
		}
	}
	else
	{
		if (pos[0] > -1 + radius)
		{
			pos[0] -= speed[0];
		}
		else
		{
			move_right = true;
			random_color();
		}
	}
}

void Circle::update(void)
{
	if (speed[0] > 0.0f)
	{
		move_item_x();
	}
	if (speed[1] > 0.0f)
	{
		move_item_y();
	}
}

void Circle::move_item_y(void)
{
	if (move_up == true)
	{
		if (pos[1] < 1 - radius)
		{
			pos[1] += speed[1];
		}
		else
		{
			move_up = false;
			random_color();
		}
	}
	else
	{
		if (pos[1] > -1 + radius)
		{
			pos[1] -= speed[1];
		}
		else
		{
			move_up = true;
			random_color();
		}
	}
}

float Circle::get_radius()
{
	return radius;
}
