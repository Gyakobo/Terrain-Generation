#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include "vec3.h"

using namespace std;

struct Camera {
public:
	vec3 Position;
	vec3 Oriention = 	vec3(0.0f, 0.0f, 0.0f);
	vec3 Up = 		vec3(0.0f, 1.0f, 0.0f);

	int width;
	int height;

	float speed = 		0.1f;
	float sensitivity = 	100.0f;

	Camera(int width, int height, vec3 position);
};



#endif
