#pragma once
#include <vector>
#include "wireframe.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


std::vector<Vertex> rotate_y(std::vector<Vertex> vertices, float angle);
std::vector<Vertex> scale(std::vector<Vertex> vertices, float size);
std::vector<Vertex> translate(std::vector<Vertex> vertices, float x, float y, float z);