#include "Camera.h"

Camera::Camera(glm::vec3 obs,
		glm::vec3 vrp,
		glm::vec3 up, 
		float fov,
		float raw) : _obs(obs), _vrp(vrp), _up(up), _fov(fov), _raw(raw), _speed(3.f) {}



void Camera::processInput(const Teclado& input, float speedFrame) {
	if (input.isKeyPressed(GLFW_KEY_LEFT)) {
     	_obs.x -= speedFrame;
     	_vrp.x -= speedFrame;
    }
    if (input.isKeyPressed(GLFW_KEY_RIGHT)) {
     	_obs.x += speedFrame;
     	_vrp.x += speedFrame;     
    }
    if (input.isKeyPressed(GLFW_KEY_UP)) {
        _obs.y += speedFrame;
        _vrp.y += speedFrame;
    }
    if (input.isKeyPressed(GLFW_KEY_DOWN)) {
        _obs.y -= speedFrame;
        _vrp.y -= speedFrame;
    }
}

void Camera::update(float dt, const Teclado& input){
	float speedFrame = _speed * dt;
	processInput(input, speedFrame);
}

glm::mat4 Camera::getViewMatrix() const {
	return glm::lookAt(_obs, _vrp, _up);
}

glm::mat4 Camera::getProjectionMatrix() const {
	return glm::perspective(glm::radians(_fov), _raw, 0.1f, 100.f);
}