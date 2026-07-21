#pragma once
#include "Mesh.h"
#include "Shader.h"

class Object {
protected:
	Mesh* _mesh;
	Shader* _shader;

	glm::vec3 _position;
	glm::vec3 _scale;
	glm::vec3 _rotate;

	GLint _transLoc;

	glm::mat4 transformMatrix();

public:
	Object(Mesh* mesh, Shader* shader);
	~Object();

	void render();
};