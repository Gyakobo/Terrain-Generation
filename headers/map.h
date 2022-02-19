#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <stdio.h>
#include <vector>

#include <math.h>
#include "vec3.h"
#include "Renderable2D.h"
#include "sprite.h"

using namespace std;

class Map {
private:
	const float a = 0.25f, b = sqrt(3)/2.0f;
	vec3 coordUp[3] = 	{ vec3(0, b*a, 0), vec3(-a/2.0f, 0, 0), vec3(a/2.0f, 0, 0) }; // A, B, C
	vec3 coordDown[3] = 	{ vec3(-a/2.0f, b*a, 0), vec3(a/2.0f, b*a, 0), vec3(0, 0, 0) }; // D, E, F
	
	vector<vec3> faces = {
		coordUp[0], 				coordUp[1], 				coordUp[2], 				// 9
		coordDown[0]+vec3(a/2.0f, 0, 0), 	coordDown[1]+vec3(a/2.0f, 0, 0), 	coordDown[2]+vec3(a/2.0f, 0, 0), 	// 10
		coordUp[0]+vec3(a, 0, 0), 		coordDown[1]+vec3(a, 0, 0), 		coordDown[2]+vec3(a, 0, 0), 		// 11
		coordDown[0]+vec3(a*1.5f, 0, 0), 	coordDown[1]+vec3(a*1.5f, 0, 0), 	coordDown[2]+vec3(a*1.5f, 0, 0)		// 12
	};

	vector<Renderable2D*> sprites;
	float size = 1.0f;

public:
	Map();
	vector<Renderable2D*> getRenderables();
	void set_size(float size);
};


#endif
