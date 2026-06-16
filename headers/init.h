#include <iostream>
#include <glad\glad.h>
#include <GLFW\glfw3.h>

// initilises glfw and glad, creates a window. Returns 1 on success and 0 on fail
int init(GLFWwindow** window, int width, int height, const char* title) {
    if (!glfwInit()) {
        std::cout << "GLFW init failed" << std::endl;
        return 0;
    }

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    *window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (*window == NULL) {
        std::cout << "Window creation failed" << std::endl;
        return 0;
    }

    glfwMakeContextCurrent(*window);

    if (!gladLoadGL()) {
        std::cout << "GLAD loading failed" << std::endl;
        return 0;
    }

    glViewport(0, 0, width, height);
    return 1;
}