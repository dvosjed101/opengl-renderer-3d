#include "VAO.h"

void VAO::LinkAttrib(GLuint layout, GLint size, GLsizei stride, GLint offset) {
    glVertexAttribPointer(layout, size, GL_FLOAT, GL_FALSE, stride, (void*)(offset * sizeof(GLfloat)));
    glEnableVertexAttribArray(layout);
}

VAO::VAO() {
    glGenVertexArrays(1, &ID);
}

void VAO::Bind() {
    glBindVertexArray(ID);
}

void VAO::Unbind() {
    glBindVertexArray(0);
}

void VAO::Delete() {
    glDeleteVertexArrays(1, &ID);
}