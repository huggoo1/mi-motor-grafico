#pragma  once
#include "Object.h"
#include "Teclado.h"

class Player : public Object {
private:
	float _speed = 1.f;

	void processInput(Teclado& input, float sppedFrame);

public:
	Player(Mesh* mesh, Shader* shader);
	~Player();

	void update(float dt, Teclado& input); 
};