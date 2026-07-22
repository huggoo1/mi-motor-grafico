#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
private:
	glm::vec3 _obs;
	glm::vec3 _vrp;
	glm::vec3 _up;

	float _fov;
	float _raw;



public:
	Camera(glm::vec3 obs,
		glm::vec3 vrp,
		glm::vec3 up, 
		float fov,
		float raw);

	glm::mat4 getViewMatrix() const;
	glm::mat4 getProjectionMatrix() const;

	void setRaw(float raw) { _raw = raw; }
};