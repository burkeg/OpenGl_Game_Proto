#include "main.h"

int main(void)
{
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GLFWwindow* window = glfwCreateWindow(480, 480, "Tutorial", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	
	Circle item = Circle(0.1f, 0.2f, 0.5f, 0.5f, -0.5f, 0.2f);
	Circle item2 = Circle(0.2f, 0.3f, 0.1f, 0.0f, 0.0f, 0.1f);
	item2.set_speed(0.03f, 0.05f);
	while (!glfwWindowShouldClose(window))
	{
		//Setup View
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = (float)width / (float)height;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		//Movement


		//Color
		item.update();
		item2.update();


		draw_item(item);
		draw_item(item2);

		//Swap buffer and check for events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

void draw_item(Circle c)
{
	//Drawing
	glColor3f(c.get_red(), c.get_green(), c.get_blue());
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float degInRad = i * DEG2RAD;
		glVertex3f((cos(degInRad) * c.get_radius() + c.get_x()), (sin(degInRad) * c.get_radius() + c.get_y()), 0);
	}
	glEnd();
}
