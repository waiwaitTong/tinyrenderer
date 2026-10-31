#include <cmath>
#include "tgaimage.h"
#include "wireframe.h"

constexpr TGAColor white   = {255, 255, 255, 255}; // attention, BGRA order
constexpr TGAColor green   = {  0, 255,   0, 255};
constexpr TGAColor red     = {  0,   0, 255, 255};
constexpr TGAColor blue    = {255, 128,  64, 255};
constexpr TGAColor yellow  = {  0, 200, 255, 255};

int main(int argc, char** argv) {
    /* constexpr int width  = 64;
    constexpr int height = 64;
    TGAImage framebuffer(width, height, TGAImage::RGB);

    int ax =  7, ay =  3;
    int bx = 12, by = 37;
    int cx = 62, cy = 53;

    framebuffer.set(ax, ay, white);
    framebuffer.set(bx, by, white);
    framebuffer.set(cx, cy, white);

    framebuffer.write_tga_file("framebuffer.tga");  */
    constexpr int width  = 800;
    constexpr int height = 800;
    TGAImage image(width,height , TGAImage::RGB);
    load_obj();
  /*   for(int i=0; i<vertices.size(); i++){
        int x = (vertices[i].x + 1.) * (width-1)/2.;
        int y = (vertices[i].y + 1.) * (height-1)/2.;
        image.set(x, y, blue);
        
    } */
   for(int i=0; i<faces.size(); i++){
        Vertex v0 = vertices[faces[i].a];
        Vertex v1 = vertices[faces[i].b];
        Vertex v2 = vertices[faces[i].c];
        int x0 = (v0.x + 1.) * (width-1)/2.;
        int y0 = (v0.y + 1.) * (height-1)/2.;
        int x1 = (v1.x + 1.) * (width-1)/2.;
        int y1 = (v1.y + 1.) * (height-1)/2.;
        int x2 = (v2.x + 1.) * (width-1)/2.;
        int y2 = (v2.y + 1.) * (height-1)/2.;
        line(x0, y0, x1, y1, image, blue);
        line(x1, y1, x2, y2, image, blue);
        line(x2, y2, x0, y0, image, blue);
    }
    image.write_tga_file("wireframe.tga"); 
    return 0;
}

