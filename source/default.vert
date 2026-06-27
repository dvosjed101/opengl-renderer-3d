#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;
layout (location = 3) in vec3 aNormal;

out vec3 color;
out vec2 texCoord;
out vec3 currentPos;
out vec3 normal;

uniform mat4 camMat;

void main() {
   color = aColor;
   texCoord = aTex;
   currentPos = aPos;
   normal = aNormal;
   gl_Position = camMat * vec4(aPos, 1.0);
}