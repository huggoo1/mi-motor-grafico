#define GL_GLEXT_PROTOTYPES
#include "Player.h"

Player::Player(Mesh* mesh, Shader* shader) : Object(mesh, shader) {}
Player::~Player() {}

void Player::processInput(Teclado& input, float speedFrame) {
	if (input.isKeyPressed(GLFW_KEY_A)) {
     	_position.x -= speedFrame;
    }
    if (input.isKeyPressed(GLFW_KEY_D) ) {
     	_position.x += speedFrame;     
    }
    if (input.isKeyPressed(GLFW_KEY_W)) {
        _position.y += speedFrame;
    }
    if (input.isKeyPressed(GLFW_KEY_S)) {
        _position.y -= speedFrame;
    }
}


void Player::update(float dt, Teclado& input) {
	float speedFrame = _speed * dt;
	processInput(input, speedFrame);
}