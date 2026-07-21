#ifndef WINDOW_H
#define WINDOW_H
#include <GLFW/glfw3.h>

class Window {
private:
	GLFWwindow* _window;
	int _width;
	int _height;
	const char* _title;

public:
	Window(int w, int h, const char* t);
	~Window();

	bool init();
	bool createWindow();
	bool shouldClose() const;
	void clear(float a, float b, float c, float d) const;
	void swapBuffers() const;
	void pollEvents() const;
	void updateDimension();

	int getWidth() const { return _width; }
	int getHeight() const { return _height; }

	GLFWwindow* getNativeWindow() const {return _window;}
};

#endif