#define GL_GLEXT_PROTOTYPES
#include "Object.h"
#include <cassert>

Object::Object(Mesh* mesh, Shader* shader) : _mesh(mesh), _shader(shader){
	_position = glm::vec3(0.f);
	_scale = glm::vec3(1.f);
	_rotate = glm::vec3(0.f);

	if (!shader) assert(false && "No shader valido");

	_transLoc = glGetUniformLocation(_shader->getId(), "TG");
}

Object::~Object() {}

glm::mat4 Object::transformMatrix() {
	glm::mat4 TG(1.f);

	TG = glm::translate(TG, _position);

	return TG;
}

void Object::render(){
	if (!_mesh || !_shader) return;

	_shader->bind();
	glm::mat4 TG = transformMatrix();
	glUniformMatrix4fv(_transLoc, 1, GL_FALSE, &TG[0][0]);

	_mesh->draw();
}

