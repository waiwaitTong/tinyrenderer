#include <cmath>
#include "tgaimage.h"
#include "wireframe.h"
#include "transform.h"
#include "perspective.h"


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
    constexpr int height = 600;
    TGAImage image(width,height , TGAImage::RGB);
    load_obj();
    if (vertices.empty() || faces.empty()) {
        return 1;
    }

    PerspectiveCamera camera;
    camera.width = width;
    camera.height = height;
    camera.vertical_fov_degrees = 60.0f;
    camera.near_plane = 0.1f;

    // Identity view: the camera is at the world origin, looking along -Z.
    // Rotate local vertices, then move the model in front of this camera.
    const auto model_vertices = rotate_y(vertices, 30.0f);
    const auto camera_vertices = translate(model_vertices, 0.0f, 0.0f, -3.0f);
    std::vector<ScreenPoint> screen_vertices;
    screen_vertices.reserve(camera_vertices.size());
    for (const auto& vertex : camera_vertices) {
        // Even invalid points retain their original index.
        screen_vertices.push_back(project_perspective(vertex, camera));
    }

    // This introductory scene is inside the viewport and beyond the near plane.
    // Crossing the near plane needs segment clipping; currently such edges skip.
    for (const auto& face : faces) {
        const int indices[3] = {face.a, face.b, face.c};
        for (int k = 0; k < 3; ++k) {
            const auto& a = screen_vertices[indices[k]];
            const auto& b = screen_vertices[indices[(k + 1) % 3]];
            if (!a.valid || !b.valid) {
                continue;
            }
            line(static_cast<int>(std::lround(a.x)), static_cast<int>(std::lround(a.y)),
                 static_cast<int>(std::lround(b.x)), static_cast<int>(std::lround(b.y)),
                 image, blue);
        }
    }

    image.write_tga_file("perspective.tga");
    return 0;
}

