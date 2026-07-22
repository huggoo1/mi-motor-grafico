#include "Camera.h"

Camera::Camera(glm::vec3 obs,
		glm::vec3 vrp,
		glm::vec3 up, 
		float fov,
		float raw) : _obs(obs), _vrp(vrp), _up(up), _fov(fov), _raw(raw) {}

glm::mat4 Camera::getViewMatrix() const {
	return glm::lookAt(_obs, _vrp, _up);
}

glm::mat4 Camera::getProjectionMatrix() const {
	return glm::perspective(glm::radians(_fov), _raw, 0.1f, 100.f);
}