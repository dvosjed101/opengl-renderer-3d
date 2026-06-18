#include "camera.h"

Camera::Camera(GLFWwindow* window, int width, int height, glm::vec3 pos) {
    UP = glm::vec3(0.0f, 1.0f, 0.0f);
    Camera::width = width;
    Camera::height = height;
    position = pos;
    orientation = glm::vec3(0.0f, 0.0f, 1.0f);
    
    // Hide the cursor and set it in the middle of the window
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    glfwSetCursorPos(window, (width / 2), (height / 2));
}

void Camera::UpdateMatrix(float FOVdeg, float nearPlane, float farPlane, Shader &shader, const char* uniform) {
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 proj = glm::mat4(1.0f);

    view = glm::lookAt(position, position + orientation, UP);
    proj = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

    glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(proj * view));
}

void Camera::handleInput(GLFWwindow* window, float dt) {
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		position += speed * orientation * dt;

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		position += speed * -glm::normalize(glm::cross(orientation, UP)) * dt;

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		position += speed * -orientation * dt;

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) 
		position += speed * glm::normalize(glm::cross(orientation, UP)) * dt;

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) 
		position += speed * UP * dt;

	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		position += speed * -UP * dt;

	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		speed = 1.0f;

	else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
		speed = 0.6f;

    // Stores the coordinates of the cursor
    double mouseX;
    double mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY);

    float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
    float rotY = sensitivity * (float)(mouseX - (width / 2)) / width;

    // Calculates upcoming vertical change in the Orientation
    glm::vec3 newOrientation = glm::rotate(orientation, glm::radians(-rotX), glm::normalize(glm::cross(orientation, UP)));

    // Decides whether or not the next vertical Orientation is legal or not
    if (abs(glm::angle(newOrientation, UP) - glm::radians(90.0f)) <= glm::radians(85.0f))
    {
        orientation = newOrientation;
    }

    // Rotates the Orientation left and right
    orientation = glm::rotate(orientation, glm::radians(-rotY), UP);

    glfwSetCursorPos(window, (width / 2), (height / 2));
}