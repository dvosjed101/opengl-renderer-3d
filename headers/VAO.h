#ifndef VAO_H
#define VAO_H

#include <glad\glad.h>

class VAO {
public:
    GLuint ID;

    VAO();
    void LinkAttrib(GLuint layout, GLint size, GLsizei stride, GLint offset);
    void Bind();
    void Unbind();
    void Delete();
};

#endif