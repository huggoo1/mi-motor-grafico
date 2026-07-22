#define GL_GLEXT_PROTOTYPES
#include <GLFW/glfw3.h> 
#include "Window.h"
#include "Shader.h"
#include "Mesh.h"
#include "Teclado.h"
#include "Player.h"
#include "Camera.h"
#include "Renderer.h"

int main() {
    Window win(800, 600, "Mi Motor Grafico");
    if (!win.init() || !win.createWindow()) return -1;

    Renderer renderer;
    
    float vertices[] = {
         0.0f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,
         0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f
    };

    glEnable(GL_DEPTH_TEST);

    Shader program("shaders/vertex.glsl", "shaders/fragment.glsl");
    Mesh mesh_triangulo(vertices, sizeof(vertices), 6);
    Player triangulo(&mesh_triangulo, &program);
    Teclado input(win.getNativeWindow());
    Camera camera(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 45.0f, 800.0f / 600.0f);
        
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
        renderer.clear();
        renderer.draw(triangulo, camera);

        win.swapBuffers();
        win.pollEvents();
    }

    return 0;
}