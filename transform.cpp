#include"transform.h"
std::vector<Vertex> rotate_y(std::vector<Vertex> vertices, float angle){
    std::vector<Vertex> new_vertices=vertices;
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
    for(auto &v: new_vertices){
        glm::vec4 vec(v.x, v.y, v.z, 1.0f);
        vec = model * vec;
        v.x = vec.x;
        v.y = vec.y;
        v.z = vec.z;
    }
    return new_vertices;
}

std::vector<Vertex> scale(std::vector<Vertex> vertices, float size){
    std::vector<Vertex> new_vertices=vertices;
    glm::mat3 matrix=glm::mat3(size);
    for(auto &v: new_vertices){
        glm::vec3 vec(v.x, v.y, v.z);
        vec = matrix * vec;
        v.x = vec.x;
        v.y = vec.y;
        v.z = vec.z;
    }
    return new_vertices;
}

std::vector<Vertex> translate(std::vector<Vertex> vertices, float x, float y, float z){
    std::vector<Vertex> new_vertices=vertices;
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(x, y, z));
    for(auto &v: new_vertices){
        glm::vec4 vec(v.x, v.y, v.z, 1.0f);
        vec = model * vec;
        v.x = vec.x;
        v.y = vec.y;
        v.z = vec.z;
    }
    return new_vertices;
}