#include "main.h"
#include "WindowUtilites.h"

float window_ratio;

int main(void)
{
	
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_SAMPLES, 8);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	//GLFWwindow* window = glfwCreateWindow(480, 480, "Tutorial", glfwGetPrimaryMonitor(), NULL);
	GLFWwindow* window = glfwCreateWindow(480, 480, "Tutorial", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	/* Set key callback */
	glfwSetKeyCallback(window, key_callback);

	Circle item = Circle(0.1f, 0.2f, 0.5f, 0.5f, -0.5f, 0.5f);
	Circle item2 = Circle(0.2f, 0.3f, 0.1f, 0.0f, 0.0f, 0.1f);
	item2.set_speed(0.03f, 0.05f);
	while (!glfwWindowShouldClose(window))
	{
		//Setup View
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		window_ratio = (float)height / (float)width;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

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


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}


}



void draw_item(Circle c)
{
	//Drawing
	glColor3f(c.get_red(), c.get_green(), c.get_blue());
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float degInRad = i * DEG2RAD;
		glVertex3f((cos(degInRad) * c.get_radius() * window_ratio + c.get_x()), (sin(degInRad) * c.get_radius() + c.get_y()), 0);
	}
	glEnd();
}
