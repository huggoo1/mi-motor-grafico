#include "Teclado.h"

Teclado::Teclado(GLFWwindow* w) : _nativeWindow(w) {}
Teclado::~Teclado() {}

bool Teclado::isKeyPressed(int key) const {
	return glfwGetKey(_nativeWindow, key) == GLFW_PRESS;
}

void Teclado::wantClose() const {
	if (glfwGetKey(_nativeWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
		glfwSetWindowShouldClose(_nativeWindow, true);
}