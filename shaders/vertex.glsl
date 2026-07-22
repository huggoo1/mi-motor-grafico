#version 330 core

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec3 color;

uniform mat4 TG;
uniform mat4 View;
uniform mat4 Proj;

out vec3 fcolor;

void main() {
	gl_Position = Proj * View * TG * vec4(vertex, 1.0);	
	fcolor = color;
}
