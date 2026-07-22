#pragma once
#include <string>
#include <vector>

class ModelLoader {
public:
	static bool loadOBJ(const std::string& path, std::vector<float>& outVertexs);
};