#include "init.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "shader.h"
#include "camera.h"
#include "texture.h"

#define WIDTH  800
#define HEIGHT 800

std::vector<GLfloat> vertices = {
//       POSITIONS 			   COLORS         UV coords         Normals
	-0.5f, -0.5f,  0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   0.0f,  0.0f,  1.0f,
	 0.5f, -0.5f,  0.5f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f,   0.0f,  0.0f,  1.0f,
	-0.5f,  0.5f,  0.5f,   0.0f, 0.0f, 1.0f,   1.0f, 1.0f,   0.0f,  0.0f,  1.0f,
	 0.5f,  0.5f,  0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   0.0f,  0.0f,  1.0f,
	 
	-0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   0.0f,  0.0f, -1.0f,
	 0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f,   0.0f,  0.0f, -1.0f,
	-0.5f,  0.5f, -0.5f,   0.0f, 0.0f, 1.0f,   1.0f, 1.0f,   0.0f,  0.0f, -1.0f,
	 0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   0.0f,  0.0f, -1.0f,
	 
	-0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,  -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f,  0.5f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f,  -1.0f,  0.0f,  0.0f,
	-0.5f,  0.5f, -0.5f,   0.0f, 0.0f, 1.0f,   1.0f, 1.0f,  -1.0f,  0.0f,  0.0f,
	-0.5f,  0.5f,  0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,  -1.0f,  0.0f,  0.0f,
	 
	 0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f,   1.0f,  0.0f,  0.0f,
	 0.5f,  0.5f, -0.5f,   0.0f, 0.0f, 1.0f,   1.0f, 1.0f,   1.0f,  0.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   1.0f,  0.0f,  0.0f,

	-0.5f,  0.5f, -0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f, -0.5f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f,   0.0f,  1.0f,  0.0f,
	-0.5f,  0.5f,  0.5f,   0.0f, 0.0f, 1.0f,   1.0f, 1.0f,   0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   0.0f,  1.0f,  0.0f,

	-0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f,   0.0f, -1.0f,  0.0f,
	-0.5f, -0.5f,  0.5f,   0.0f, 0.0f, 1.0f,   1.0f, 1.0f,   0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   0.0f, -1.0f,  0.0f,
};


std::vector<GLuint> indices = {
	0, 1, 2,
	1, 2, 3,

	4, 5, 6,
	5, 6, 7,

	8, 9, 10,
	9, 10, 11,

	12, 13, 14,
	13, 14, 15,

	16, 17, 18,
	17, 18, 19,

	20, 21, 22,
	21, 22, 23
};


/// light cube
std::vector<GLfloat> verticesLight = {
//       POSITIONS
	-0.5f, -0.5f,  0.5f,
	 0.5f, -0.5f,  0.5f,
	-0.5f,  0.5f,  0.5f,
	 0.5f,  0.5f,  0.5f,
	 
	-0.5f, -0.5f, -0.5f,
	 0.5f, -0.5f, -0.5f,
	-0.5f,  0.5f, -0.5f,
	 0.5f,  0.5f, -0.5f,
	 
	-0.5f, -0.5f, -0.5f,
	-0.5f, -0.5f,  0.5f,
	-0.5f,  0.5f, -0.5f,
	-0.5f,  0.5f,  0.5f,
	 
	 0.5f, -0.5f, -0.5f,
	 0.5f, -0.5f,  0.5f,
	 0.5f,  0.5f, -0.5f,
	 0.5f,  0.5f,  0.5f,

	-0.5f,  0.5f, -0.5f,
	 0.5f,  0.5f, -0.5f,
	-0.5f,  0.5f,  0.5f,
	 0.5f,  0.5f,  0.5f,

	-0.5f, -0.5f, -0.5f,
	 0.5f, -0.5f, -0.5f,
	-0.5f, -0.5f,  0.5f,
	 0.5f, -0.5f,  0.5f,
};


std::vector<GLuint> indicesLight = {
	0, 1, 2,
	1, 2, 3,

	4, 5, 6,
	5, 6, 7,

	8, 9, 10,
	9, 10, 11,

	12, 13, 14,
	13, 14, 15,

	16, 17, 18,
	17, 18, 19,

	20, 21, 22,
	21, 22, 23
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

	vao.LinkAttrib(0, 3, 11 * sizeof(GLfloat), 0);
	vao.LinkAttrib(1, 3, 11 * sizeof(GLfloat), 3);
	vao.LinkAttrib(2, 2, 11 * sizeof(GLfloat), 6);
	vao.LinkAttrib(3, 3, 11 * sizeof(GLfloat), 8);

	vao.Unbind();
	vbo.Unbind();
	ebo.Unbind();


	Camera cam(window, WIDTH, HEIGHT, glm::vec3(0.0f, 0.0f, 2.0f));

	Texture tex("testImage.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	tex.texUnit(shaderProgram, "tex0", 0);



	


	float lightCubeScale = 0.25;
	glm::vec3 lightPos = glm::vec3(2.0f, 1.0f, 1.0f);
	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	VAO vaoLight;

	vaoLight.Bind();

	VBO vboLight(verticesLight);
	EBO eboLight(indicesLight);

	vboLight.Bind();

	vaoLight.LinkAttrib(0, 3, 3 * sizeof(GLfloat), 0);

	vaoLight.Unbind();
	vboLight.Unbind();
	eboLight.Unbind();

	Shader shaderProgramLight("source/light.vert", "source/light.frag");

	shaderProgramLight.Activate();
	glUniform4f(glGetUniformLocation(shaderProgramLight.ID, "lightColor"), lightColor.r, lightColor.g, lightColor.b, lightColor.a);

	glm::mat4 lightModelMat = glm::mat4(1.0f);
	lightModelMat = glm::translate(lightModelMat, lightPos);
	lightModelMat = glm::scale(lightModelMat, glm::vec3(lightCubeScale));

	glUniformMatrix4fv(glGetUniformLocation(shaderProgramLight.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModelMat));








	shaderProgram.Activate();
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.r, lightColor.g, lightColor.b, lightColor.a);




	glfwSwapInterval(1);
	glEnable(GL_DEPTH_TEST);

	float deltaTime = 0.0f;
	float lastFrame = glfwGetTime();

	while (!glfwWindowShouldClose(window)) {
		float now = glfwGetTime();
		deltaTime = now - lastFrame;
		lastFrame = now;


		glClearColor(0.498f, 0.722f, 0.902f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shaderProgram.Activate();

		glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), cam.position.x, cam.position.y, cam.position.z);

		vao.Bind();
		tex.Bind();
		
		cam.UpdateMatrix(60, 0.1f, 100.0f, shaderProgram, "camMat");

		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);



		shaderProgramLight.Activate();
		vaoLight.Bind();

		cam.UpdateMatrix(60, 0.1f, 100.0f, shaderProgramLight, "camMat");

		glDrawElements(GL_TRIANGLES, indicesLight.size(), GL_UNSIGNED_INT, 0);
		



		glfwSwapBuffers(window);
		glfwPollEvents();
		cam.handleInput(window, deltaTime);
	}

	vao.Delete();
	vbo.Delete();
	ebo.Delete();
	vaoLight.Delete();
	vboLight.Delete();
	eboLight.Delete();
	shaderProgram.Delete();
	shaderProgramLight.Delete();
	tex.Delete();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}