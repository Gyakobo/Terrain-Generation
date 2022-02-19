#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <math.h>
#include "vec3.h"

using namespace std;

class Map {
private:
	const float a = 0.25f, b = sqrt(3)/2.0f;
	const vec3 coordUp[3] = 	{ vec3(0, b*a, 0), vec3(-a/2.0f, 0, 0), vec3(a/2.0f, 0, 0) }; // A, B, C
	const vec3 coordDown[3] = 	{ vec3(-a/2.0f, b*a, 0), vec3(a/2.0f, b*a, 0), vec3(0, 0, 0) }; // D, E, F
	vector<vec3> faces = {
	};

public:
	Map();

};


#endif
