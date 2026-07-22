#pragma once
#include "Object.h"
#include "Camera.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    void clear(float r = 0.1f, float g = 0.1f, float b = 0.14f, float a = 1.0f) const;
    void draw(const Object& object, const Camera& camera) const;
};