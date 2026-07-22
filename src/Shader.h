#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/gl.h>
#include <GL/glext.h>
#include <glm/glm.hpp>

class Shader {
private:
	GLuint _program;

	std::string readShader(const char* path);
	void checkCompileErrors(GLuint shader, std::string type); 

public:
	Shader(const char* vertPath, const char* fragPath);
	~Shader();

	void bind() const;
	void release() const;

	GLuint getId() const { return _program; }

	void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setVec3(const std::string& name, const glm::vec3& value) const;
    void setMat4(const std::string& name, const glm::mat4& mat) const;
};

#endif