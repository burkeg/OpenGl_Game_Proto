#ifndef ITEM_H
#define ITEM_H


#include "linmath.h"
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class Item
{
protected:
	float rgb [3];
	float pos[2];
	float speed[2];
	bool move_right;
	bool move_up;
	void move_item_x();
	void move_item_y();
	void random_color();



public:
	Item(float r, float g, float b, float x, float y);

	void update(void); 
	void set_color(float r, float g, float b);
	void set_pos(float x, float y);
	void set_speed(float x_dt, float y_dt);
	float get_red();
	float get_green();
	float get_blue();
	float get_x();
	float get_y();
};

#endif