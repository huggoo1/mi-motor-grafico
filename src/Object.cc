#define GL_GLEXT_PROTOTYPES
#include "Object.h"
#include <glm/gtc/matrix_transform.hpp>
#include <cassert>

Object::Object(Mesh* mesh, Shader* shader) : _mesh(mesh), _shader(shader) {
    _position = glm::vec3(0.f);
    _scale    = glm::vec3(1.f);
    _rotate   = glm::vec3(0.f);

    if (!shader) assert(false && "No shader valido");
}

Object::~Object() {}

glm::mat4 Object::getTransformMatrix() const {
    glm::mat4 TG(1.f);
    TG = glm::translate(TG, _position);
    TG = glm::rotate(TG, glm::radians(_rotate.x), glm::vec3(1, 0, 0));
    TG = glm::rotate(TG, glm::radians(_rotate.y), glm::vec3(0, 1, 0));
    TG = glm::rotate(TG, glm::radians(_rotate.z), glm::vec3(0, 0, 1));
    TG = glm::scale(TG, _scale);
    return TG;
}