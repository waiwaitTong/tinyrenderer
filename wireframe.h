#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include "tgaimage.h"
#include <cmath>

struct Vertex {
    float x, y, z;
};
struct Face {
    int a, b, c;
};
extern std::vector<Vertex> vertices;
extern std::vector<Face> faces;
void load_obj();
void line(int x0, int y0, int x1, int y1, TGAImage &image, const TGAColor &color);


