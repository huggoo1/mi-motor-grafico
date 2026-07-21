#define GL_GLEXT_PROTOTYPES
#include "Mesh.h"
#include <cassert>


Mesh::Mesh(const float* att, size_t sB, size_t aPV) : _countVertex(sB / (aPV * sizeof(float))){
	glGenVertexArrays(1, &_VAO);
	glBindVertexArray(_VAO);

	glGenBuffers(1, &_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	glBufferData(GL_ARRAY_BUFFER, sB, att, GL_STATIC_DRAW);
	
	//VERTEXS	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, aPV * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//COLORS
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, aPV * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	//DESACTIVAR
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Mesh::draw() const {
	glBindVertexArray(_VAO);
	glDrawArrays(GL_TRIANGLES, 0, _countVertex);

	//DESACTIVAR
	glBindVertexArray(0);
}

Mesh::~Mesh(){
	glDeleteBuffers(1, &_VBO);
	glDeleteVertexArrays(1, &_VAO);
}
