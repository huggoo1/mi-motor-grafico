#define GL_GLEXT_PROTOTYPES
#include "Window.h"
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>

Window::Window(int w, int h, const char* t) :	_window(nullptr), _width(w), _height(h), _title(t){}

Window::~Window() {
	if (_window) glfwDestroyWindow(_window);
	glfwTerminate();
}


bool Window::init() {
	if (!glfwInit()) {
		std::cerr << "Error al Inicializar la Ventana '\n";
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	return true;
}


bool Window::createWindow() {
	if (!(_window = glfwCreateWindow(_width, _height, _title, nullptr, nullptr))) {
		std::cerr << "Error al Crear la Ventana '\n";
		return false;
	}

	glfwMakeContextCurrent(_window);
	return true;
}

bool Window::shouldClose() const {
	return glfwWindowShouldClose(_window);
}

void Window::clear(float a, float b, float c, float d) const {
	glClearColor(a, b, c, d);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::swapBuffers() const {
	glfwSwapBuffers(_window);
}

void Window::pollEvents() const {
	glfwPollEvents();
}

void Window::updateDimension() {
	glfwGetFramebufferSize(_window, &_width, &_height);
	glViewport(0, 0, _width, _height);
}