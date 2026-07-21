#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GLFW/glfw3.h>

class Shader {
private:
	GLuint _program;

	std::string readShader(const char* path);

public:
	Shader(const char* vertPath, const char* fragPath);
	~Shader();

	void bind() const;
	void release() const;

	GLuint getId() const { return _program; }
};

#endif