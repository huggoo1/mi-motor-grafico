#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"
#include "ModelLoader.h"
#include <iostream>

bool ModelLoader::loadOBJ(const std::string& path, std::vector<float>& outVertices) {
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn, err;

    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, path.c_str());

    if (!warn.empty()) std::cout << "WARN: " << warn << std::endl;
    if (!err.empty()) std::cerr << "ERR: " << err << std::endl;
    if (!ret) return false;

    outVertices.clear();

    // Recorremos los polígonos del archivo .obj
    for (size_t s = 0; s < shapes.size(); s++) {
        size_t index_offset = 0;
        for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
            size_t fv = size_t(shapes[s].mesh.num_face_vertices[f]);

            for (size_t v = 0; v < fv; v++) {
                tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];

                // 1. Posición del vértice (X, Y, Z)
                float vx = attrib.vertices[3 * size_t(idx.vertex_index) + 0];
                float vy = attrib.vertices[3 * size_t(idx.vertex_index) + 1];
                float vz = attrib.vertices[3 * size_t(idx.vertex_index) + 2];

                outVertices.push_back(vx);
                outVertices.push_back(vy);
                outVertices.push_back(vz);

                // 2. Asignación de Color (R, G, B)
                // Como los .obj no suelen traer colores por vértice, usamos sus Normales
                // para darle un color basado en la orientación de la superficie.
                if (idx.normal_index >= 0) {
                    float nx = attrib.normals[3 * size_t(idx.normal_index) + 0];
                    float ny = attrib.normals[3 * size_t(idx.normal_index) + 1];
                    float nz = attrib.normals[3 * size_t(idx.normal_index) + 2];

                    // Convertimos el rango [-1, 1] de la normal al rango [0, 1] de color RGB
                    outVertices.push_back(nx * 0.5f + 0.5f);
                    outVertices.push_back(ny * 0.5f + 0.5f);
                    outVertices.push_back(nz * 0.5f + 0.5f);
                } else {
                    // Color por defecto si no tiene normales (Gris claro)
                    outVertices.push_back(0.7f);
                    outVertices.push_back(0.7f);
                    outVertices.push_back(0.7f);
                }
            }
            index_offset += fv;
        }
    }
    return true;
}