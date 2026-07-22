#ifndef MESH_H
#define MESH_H

#include <GL/gl.h>
#include <GL/glext.h>
#include <cstddef>

class Mesh {
private:

	//DATOS MODELO
	GLuint _VAO, _VBO;
	size_t _countVertex;

public:
	Mesh(const float* atributes, size_t sizeBytes, size_t attPerVertex);
	~Mesh();

	void draw() const;
};

#endif