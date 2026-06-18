#include "init.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "shader.h"

#define WIDTH  800
#define HEIGHT 800

std::vector<GLfloat> vertices = {
//   POSITIONS
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	-0.5f,  0.5f, 0.0f,
	 0.5f,  0.5f, 0.0f,
};

std::vector<GLuint> indices = {
	0, 1, 2,
	1, 2, 3
};

int main() {
	GLFWwindow* window;
	if (!init(&window, WIDTH, HEIGHT, "Rendering engine")) {
		std::cout << "Error, exiting program" << std::endl;
		return 1;
	}



	Shader shaderProgram("source/default.vert", "source/default.frag");



	VAO vao;

	vao.Bind();

	VBO vbo(vertices);
	EBO ebo(indices);

	vbo.Bind();

	vao.LinkAttrib(0, 3, 3 * sizeof(GLfloat), 0);

	vao.Unbind();
	vbo.Unbind();
	ebo.Unbind();


	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.498f, 0.722f, 0.902f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shaderProgram.Activate();

		vao.Bind();

		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	vao.Delete();
	vbo.Delete();
	ebo.Delete();
	shaderProgram.Delete();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}