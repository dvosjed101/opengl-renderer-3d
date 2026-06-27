#version 330 core

out vec4 FragColor;
in vec3 color;
in vec2 texCoord;
in vec3 currentPos;
in vec3 normal;

uniform sampler2D tex0;
uniform vec3 lightPos;
uniform vec4 lightColor;

void main() {
   float ambientLight = 0.125f;
   vec3 Normal = normalize(normal);
   vec3 lightDirection = normalize(lightPos - currentPos);

   float diffuse = max(dot(Normal, lightDirection), 0.0f);

   FragColor = texture(tex0, texCoord) * (diffuse + ambientLight) * lightColor;
}