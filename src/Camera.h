#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Teclado.h"

class Camera {
private:
	glm::vec3 _obs;
	glm::vec3 _vrp;
	glm::vec3 _up;

	float _fov;
	float _raw;
	float _speed;

	void processInput(const Teclado& input, float spedFrame);

public:
	Camera(glm::vec3 obs,
		glm::vec3 vrp,
		glm::vec3 up, 
		float fov,
		float raw);

	void update(float dt, const Teclado& input);

	glm::mat4 getViewMatrix() const;
	glm::mat4 getProjectionMatrix() const;

	void setRaw(float raw) { _raw = raw; }
};