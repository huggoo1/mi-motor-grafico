#ifndef MESH_H
#define MESH_H

#include <GL/gl.h>
#include <GL/glext.h>
#include <cstddef>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Mesh {
private:
	
	//DATOS MODELO
	GLuint _VAO, _VBO;
	float _countVertex;

public:
	Mesh(const float* atributes, size_t sizeBytes, size_t attPerVertex);
	~Mesh();

	void draw() const;
};

#endif