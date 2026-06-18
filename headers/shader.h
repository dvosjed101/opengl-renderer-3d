#ifndef SHADER_H
#define SHADER_H

#include <glad\glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string get_file_contents();

class Shader {
public:
    GLuint ID;

    Shader(const char* vertexSource, const char* fragmentSource);
    void CheckCompile(GLuint shader, const char* type);
    void Activate();
    void Delete();
};

#endif