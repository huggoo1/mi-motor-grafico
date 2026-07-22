#define GL_GLEXT_PROTOTYPES
#include "Renderer.h"
#include <GL/gl.h>

Renderer::Renderer() {
    glEnable(GL_DEPTH_TEST);
}

Renderer::~Renderer() {}

void Renderer::clear(float r, float g, float b, float a) const {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
}

void Renderer::draw(const Object& object, const Camera& camera) const {
    Shader* shader = object.getShader();
    Mesh* mesh     = object.getMesh();

    if (!shader || !mesh) return;
    shader->bind();

    shader->setMat4("View", camera.getViewMatrix());
    shader->setMat4("Proj", camera.getProjectionMatrix());
    shader->setMat4("TG", object.getTransformMatrix());

    mesh->draw();
}