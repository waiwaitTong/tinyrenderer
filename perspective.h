#pragma once

#include "wireframe.h"

// Camera space: +X right, +Y up, camera looks along -Z.
struct PerspectiveCamera {
    int width = 800;
    int height = 600;
    float vertical_fov_degrees = 60.0f;
    float near_plane = 0.1f;
};

struct ScreenPoint {
    float ndc_x = 0.0f;
    float ndc_y = 0.0f;
    float x = 0.0f;
    float y = 0.0f;
    float depth = 0.0f; // Positive camera distance, not NDC depth.
    // Projectable does not mean inside the viewport.
    bool valid = false;
};

// Continuous screen coordinates: top-left origin, +Y down.
// Returns valid=false for bad parameters or a point before the near plane.
ScreenPoint project_perspective(const Vertex& camera_point,
                                const PerspectiveCamera& camera);
