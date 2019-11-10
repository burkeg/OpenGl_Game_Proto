#include <GLFW/glfw3.h>
#include "linmath.h"
#include <stdlib.h>
#include <stdio.h>
#include "Shape.h"
#include "Circle.h"

constexpr float DEG2RAD = (3.1415926535f / 180.0f);


void draw_item(Circle c, float ratio);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
