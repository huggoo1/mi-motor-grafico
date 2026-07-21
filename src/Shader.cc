#define GL_GLEXT_PROTOTYPES
#include "Shader.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

Shader::Shader(const char* vp, const char* fp) {
	std::string textVertex = readShader(vp);
	std::string textFrag = readShader(fp);

	const char* startVertex = textVertex.c_str();
	const char* startFrag = textFrag.c_str();

	//CREATE VERTEX SHADER
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &startVertex, NULL);
	glCompileShader(vs);

	//CREATE FRAGMENT SHADER
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &startFrag, NULL);
	glCompileShader(fs);

	//CREATE PROGRAM
	_program = glCreateProgram();
	glAttachShader(_program, vs);
	glAttachShader(_program, fs);
	glLinkProgram(_program);

	glDeleteShader(vs);
	glDeleteShader(fs);
}

Shader::~Shader() {
	glDeleteProgram(_program);
}

std::string Shader::readShader(const char* path) {
	std::ifstream file(path);
	if (!file.is_open()) {
		std::cerr << "Error al abrir el Archivo" << path << '\n';
		return "";
	}

	std::stringstream ss;
	ss << file.rdbuf();

	return ss.str();
}


void Shader::bind() const {
	glUseProgram(_program);
}

void Shader::release() const {
	glUseProgram(0);
}
