#version 330 core

out vec4 FragColor;
in vec3 color;
in vec2 texCoord;
in vec3 currentPos;
in vec3 normal;

uniform sampler2D tex0;
uniform vec3 lightPos;
uniform vec4 lightColor;
uniform vec3 camPos;

void main() {
   float ambientLight = 0.125f;
   vec3 Normal = normalize(normal);
   vec3 lightDirection = normalize(lightPos - currentPos);

   float diffuse = max(dot(Normal, lightDirection), 0.0f);

   float specularLight = 0.50f;
	vec3 viewDirection = normalize(camPos - currentPos);
	vec3 reflectionDirection = reflect(-lightDirection, normal);
	float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 8);
	float specular = specAmount * specularLight;

   FragColor = texture(tex0, texCoord) * (diffuse + ambientLight + specular) * lightColor;
}