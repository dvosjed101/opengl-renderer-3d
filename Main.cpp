#include "init.h"
#include "VAO.h"
#include "VBO.h"

#define WIDTH  800
#define HEIGHT 800

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.769f, 0.408f, 0.353f, 1.0f);\n"
"}\n\0";

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


	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


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

		glUseProgram(shaderProgram);

		vao.Bind();

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	vao.Delete();
	vbo.Delete();
	glDeleteShader(shaderProgram);
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}