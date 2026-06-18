#include "init.h"
#include "VAO.h"
#include "VBO.h"
#include "shader.h"

#define WIDTH  800
#define HEIGHT 800

std::vector<GLfloat> vertices = {
//   POSITIONS
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
};

int main() {
	GLFWwindow* window;
	if (!init(&window, WIDTH, HEIGHT, "Rendering engine")) {
		std::cout << "Error, exiting program" << std::endl;
		return 1;
	}

	Shader shaderProgram("source/default.vert", "source/default.frag");

	VAO vao;
	VBO vbo(vertices);

	vbo.Bind();
	vao.Bind();

	vao.LinkAttrib(0, 3, 3 * sizeof(GLfloat), 0);

	vao.Unbind();
	vbo.Unbind();


	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.498f, 0.722f, 0.902f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shaderProgram.Activate();

		vao.Bind();

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	vao.Delete();
	vbo.Delete();
	shaderProgram.Delete();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}