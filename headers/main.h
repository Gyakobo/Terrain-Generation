#ifndef MAIN_H
#define MAIN_H

// Basics 
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdint>

// Window
#include "Window.h"

// Math
#include "mat4.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

// Renderers
#include "Shader.h"
#include "BatchRenderer2D.h"
#include "sprite.h"
#include "Renderable2D.h"
#include "Renderer2D.h"
#include "Buffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "tilelayer.h"
#include "Layer.h"
#include "SimplexNoise.h"

// Terrain Rendering
#include "TerrainFace.h"
#include "Planet.h"

// Utilities
#include "camera.h"

// Example Shapes
#include "Icosahedron.h"
#include "map.h"

const float a = 0.525731112119133606f;
const float b = 0.850650808352039932f;

const int indices[20][3] = {
        {0,1,4}, {0,4,9}, {9,4,5}, {4,8,5}, {4,1,8},
        {8,1,10}, {8,10,3}, {5,8,3}, {5,3,2}, {2,3,7},
        {7,3,10}, {7,10,6}, {7,6,11}, {11,6,0}, {0,6,1},
        {6,10,1}, {9,11,0}, {9,2,11}, {9,5,2}, {7,11,2}
};

const vec3 FaceCoord[12] = {
        vec3(-a, 0.0f, b),      vec3(a, 0.0f, b),       vec3(-a, 0.0f, -b), vec3(a, 0.0f, -b),
        vec3(0.0f, b, a),       vec3(0.0f, b, -a),      vec3(0.0f, -b, a),  vec3(0.0f, -b, -a),
        vec3(b, a, 0.0f),       vec3(-b, a, 0.0f),      vec3(b, -a, 0.0f),  vec3(-b, -a, 0.0f)
};

#endif
