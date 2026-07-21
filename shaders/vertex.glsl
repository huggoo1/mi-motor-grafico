#version 330 core

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec3 color;
uniform mat4 TG;

out vec3 fcolor;

void main() {
	gl_Position = TG * vec4(vertex, 1.0);	
	fcolor = color;
}
