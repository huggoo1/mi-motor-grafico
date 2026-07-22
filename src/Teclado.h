#pragma once
#include <GLFW/glfw3.h>

class Teclado {
private: 
	GLFWwindow* _nativeWindow;

public:
	Teclado(GLFWwindow* w);
	~Teclado();

	bool isKeyPressed(int key) const;
	void wantClose() const;
};