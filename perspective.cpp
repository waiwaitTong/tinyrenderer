// C++ implementation despite the requested .c suffix.
// CMake copies this file to an ASCII-named .cpp for older MinGW toolchains.
#include "perspective.h"

#include <cmath>

ScreenPoint project_perspective(const Vertex& p, const PerspectiveCamera& camera) {
    ScreenPoint result;
    if (camera.width <= 0 || camera.height <= 0 ||
        !std::isfinite(camera.vertical_fov_degrees) ||
        camera.vertical_fov_degrees <= 0.0f || camera.vertical_fov_degrees >= 180.0f ||
        !std::isfinite(camera.near_plane) || camera.near_plane <= 0.0f ||
        !std::isfinite(p.x) || !std::isfinite(p.y) || !std::isfinite(p.z)) {
        return result;
    }

    const float distance = -p.z;
    if (distance < camera.near_plane) {
        return result;
    }
    constexpr float pi = 3.14159265358979323846f;
    const float half_fov = camera.vertical_fov_degrees * pi / 360.0f;
    const float tan_half_fov = std::tan(half_fov);
    const float aspect = static_cast<float>(camera.width) / camera.height;

  
    result.ndc_x = p.x / (distance * aspect * tan_half_fov);
    result.ndc_y = p.y / (distance * tan_half_fov);

    result.x = (result.ndc_x + 1.0f) * 0.5f * camera.width;
    result.y = (1.0f - result.ndc_y) * 0.5f * camera.height;
    result.depth = distance;
    result.valid = std::isfinite(result.x) && std::isfinite(result.y);
    return result;
}
