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
	const float a = 0.25f, b = sqrt(3)/2.0f * a;
	vec3 coordUp[3] = 	{ vec3(0, b, 0), vec3(-a/2.0f, 0, 0), vec3(a/2.0f, 0, 0) }; // A, B, C
	vec3 coordDown[3] = 	{ vec3(-a/2.0f, b, 0), vec3(a/2.0f, b, 0), vec3(0, 0, 0) }; // D, E, F
	
	vector<vec3> faces = {
		// First Tentacle
		coordDown[0]-vec3(a*1.5f, 0, 0), 	coordDown[1]-vec3(a*1.5f, 0, 0), 	coordDown[2]-vec3(a*1.5f, 0, 0), 	// 6 
		coordUp[0]-vec3(a, 0, 0), 		coordUp[1]-vec3(a, 0, 0), 		coordUp[2]-vec3(a, 0, 0), 		// 7
		coordDown[0]-vec3(a/2.0f, 0, 0), 	coordDown[1]-vec3(a/2.0f, 0, 0), 	coordDown[2]-vec3(a/2.0f, 0, 0), 	// 8 
		coordUp[0], 				coordUp[1], 				coordUp[2], 				// 9
		coordDown[0]+vec3(a/2.0f, 0, 0), 	coordDown[1]+vec3(a/2.0f, 0, 0), 	coordDown[2]+vec3(a/2.0f, 0, 0), 	// 10
		coordUp[0]+vec3(a, 0, 0), 		coordUp[1]+vec3(a, 0, 0), 		coordUp[2]+vec3(a, 0, 0), 		// 11
		coordDown[0]+vec3(a*1.5f, 0, 0), 	coordDown[1]+vec3(a*1.5f, 0, 0), 	coordDown[2]+vec3(a*1.5f, 0, 0), 	// 12
		coordUp[0]+vec3(a*2.0f, 0, 0), 		coordUp[1]+vec3(a*2.0f, 0, 0), 		coordUp[2]+vec3(a*2.0f, 0, 0), 		// 13
		coordDown[0]+vec3(a*2.5f, 0, 0), 	coordDown[1]+vec3(a*2.5f, 0, 0), 	coordDown[2]+vec3(a*2.5f, 0, 0),	// 14

		// Second Tentacle
		coordUp[0]+vec3(-a/2.0f, b, 0), 	coordUp[1]+vec3(-a/2.0f, b, 0), 	coordUp[2]+vec3(-a/2.0f, b, 0), 	// 3 
		coordDown[0]+vec3(-a, b, 0), 		coordDown[1]+vec3(-a, b, 0), 		coordDown[2]+vec3(-a, b, 0),		// 2
		coordUp[0]+vec3(-a, b*2.0f, 0), 	coordUp[1]+vec3(-a, b*2.0f, 0), 	coordUp[2]+vec3(-a, b*2.0f, 0), 	// 1 
		coordDown[0]+vec3(0, -b, 0), 		coordDown[1]+vec3(0, -b, 0), 		coordDown[2]+vec3(0, -b, 0),		// 16
		coordUp[0]+vec3(a/2.0f, -b, 0), 	coordUp[1]+vec3(a/2.0f, -b, 0), 	coordUp[2]+vec3(a/2.0f, -b, 0), 	// 17 
		coordDown[0]+vec3(a/2.0f, -b*2.0f, 0), 	coordDown[1]+vec3(a/2.0f, -b*2.0f, 0), 	coordDown[2]+vec3(a/2.0f, -b*2.0f, 0),	// 20
	
		// Third Tentacle
		coordUp[0]+vec3(a/2.0f, b, 0), 		coordUp[1]+vec3(a/2.0f, b, 0), 		coordUp[2]+vec3(a/2.0f, b, 0), 		// 4
		coordDown[0]+vec3(a, b, 0), 		coordDown[1]+vec3(a, b, 0), 		coordDown[2]+vec3(a, b, 0), 		// 5
		coordUp[0]+vec3(-a/2.0f, -b, 0), 	coordUp[1]+vec3(-a/2.0f, -b, 0), 	coordUp[2]+vec3(-a/2.0f, -b, 0),	// 15
		coordDown[0]+vec3(-a/2.0f, -b*2.0f, 0), coordDown[1]+vec3(-a/2.0f, -b*2.0f, 0), coordDown[2]+vec3(-a/2.0f, -b*2.0f, 0),	// 19
		coordUp[0]+vec3(-a, -b*2.0f, 0), 	coordUp[1]+vec3(-a, -b*2.0f, 0), 	coordUp[2]+vec3(-a, -b*2.0f, 0),	// 18
	};

	vector<Renderable2D*> sprites;
	float size = 1.0f;

public:
	Map();
	vector<Renderable2D*> getRenderables();
	void set_size(float size);
};


#endif
