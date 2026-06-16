#include "headers/init.h"

#define WIDTH  800
#define HEIGHT 800


int main() {
	GLFWwindow* window;
	if (!init(&window, WIDTH, HEIGHT, "Rendering engine")) {
		std::cout << "Error, exiting program" << std::endl;
		return 1;
	}

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}