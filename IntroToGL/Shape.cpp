#include "Shape.h"

// Item Constructor
Shape::Shape(float r, float g, float b, float x, float y)
{
	set_color(r, g, b);
	set_pos(x, y);
	speed[0] = 0.02f;
	speed[1] = 0.01f;
	move_right, move_up = true;
}

void Shape::set_color(float r, float g, float b)
{
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
}

float Shape::get_red()
{
	return rgb[0];
}

float Shape::get_green()
{
	return rgb[1];
}

float Shape::get_blue()
{
	return rgb[2];
}

void Shape::set_pos(float x, float y)
{
	pos[0] = x;
	pos[1] = y;
}

float Shape::get_x()
{
	return pos[0];
}

float Shape::get_y()
{
	return pos[1];
}

void Shape::set_speed(float x_dt, float y_dt)
{
	speed[0] = x_dt;
	speed[1] = y_dt;
}

void Shape::update(void)
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

void Shape::move_item_x(void)
{
	if (move_right == true)
	{
		if (pos[0] < 1)
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
		if (pos[0] > -1)
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

void Shape::move_item_y(void)
{
	if (move_up == true)
	{
		if (pos[1] < 1)
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
		if (pos[1] > -1)
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

void Shape::random_color()
{
	rgb[0] = ((float)rand()) / (float)RAND_MAX;
	rgb[1] = ((float)rand()) / (float)RAND_MAX;
	rgb[2] = ((float)rand()) / (float)RAND_MAX;
}
