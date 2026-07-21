#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GLFW/glfw3.h> 
#include "Window.h"
#include "Shader.h"
#include "Mesh.h"
#include "Teclado.h"
#include "Player.h"
#include <glm/gtc/type_ptr.hpp>

int main() {
    Window win(800, 600, "Mi Motor Grafico");
    if (!win.init() || !win.createWindow()) return -1;

    
    float vertices[] = {
         0.0f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,
         0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f
    };


    Shader program("shaders/vertex.glsl", "shaders/fragment.glsl");
    Mesh mesh_triangulo(vertices, sizeof(vertices), 6);
    Player triangulo(&mesh_triangulo, &program);
    Teclado input(win.getNativeWindow());
    
    float lastFrame = 0.f;

    while (!win.shouldClose()) {
        input.wantClose();
        win.updateDimension();

        //DELTA TIME
        float frame = glfwGetTime();
        float dt = frame - lastFrame;
        lastFrame = frame;

        //UPDATE
        triangulo.update(dt, input);

        //RENDER
        win.clear(0.1f, 0.1f, 0.14f, 1.0f);
        triangulo.render();

        win.swapBuffers();
        win.pollEvents();
    }
    
    return 0;
}