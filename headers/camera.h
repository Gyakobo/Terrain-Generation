#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Shader.h"

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

mat4 lookAt(vec3& eye, vec3& center, vec3& up);

class Camera {
public:
    vec3 position;
    vec3 Orientation = vec3(0.0f, 0.0f, -1.0f);
    vec3 Up = vec3(0.0f, 1.0f, 0.0f);

    int width;
    int height;

    float speed = 0.1f;
    float sensitivity = 100.0f;

    Camera(int width, int height, vec3 position);

    void Inputs(GLFWwindow* window);

    void Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform);
};


#endif
