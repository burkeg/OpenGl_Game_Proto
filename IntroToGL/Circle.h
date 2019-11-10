#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "WindowUtilites.h"

class Circle : public Shape
{
protected:
	float radius;
	void move_item_x();
	void move_item_y();
public:
	Circle(float r, float g, float b, float x, float y, float rad);
	
	void update(void);
	float get_radius();
};

#endif