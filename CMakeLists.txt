cmake_minimum_required(VERSION 3.10)
project(MiMotorGrafico)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

# Indicamos a CMake que busque los archivos dentro de la carpeta src
add_executable(MiMotor 
    src/main.cc 
    src/Window.cc
    src/Shader.cc
    src/Mesh.cc
    src/Teclado.cc
    src/Object.cc
    src/Player.cc
    src/Camera.cc
    src/Renderer.cc
    src/ModelLoader.cc
)

# Esto le dice a tu proyecto que busque los archivos .h dentro de src
target_include_directories(MiMotor PRIVATE src)

# Enlazamos las librerías de Linux (GLFW y OpenGL)
target_link_libraries(MiMotor glfw GL)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})