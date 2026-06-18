#ifndef CAMERA_H
#define CAMERA_H

#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include "shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

class Camera {
public:
    glm::vec3 position;
    glm::vec3 orientation;
    glm::vec3 UP;

    // some default parameters
    float speed = 0.6f;
    float sensitivity = 100.0f;
    
    int width, height;
    
    Camera(GLFWwindow* window, int width, int height, glm::vec3 pos);
    void UpdateMatrix(float FOVdeg, float nearPlane, float farPlane, Shader &shader, const char* uniform);
    void handleInput(GLFWwindow* window, float dt);
};

#endif