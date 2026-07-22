#pragma once
#include "Mesh.h"
#include "Shader.h"
#include <glm/glm.hpp>

class Object {
protected:
	Mesh* _mesh;
	Shader* _shader;

	glm::vec3 _position;
	glm::vec3 _scale;
	glm::vec3 _rotate;

public:
	Object(Mesh* mesh, Shader* shader);
	~Object();

	Mesh* getMesh() const { return _mesh; }
	Shader* getShader() const { return _shader; } 
	glm::mat4 getTransformMatrix() const;
};