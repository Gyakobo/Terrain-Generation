#ifndef ICOSAHEDRON_H
#define ICOSAHEDRON_H

#include <iostream>
#include <stdio.h>
#include <math.h>

#include <vector>
#include "Renderable2D.h"
#include "sprite.h"


using namespace std;
	// Icosahedron faces
	/*const float FaceCoord[] = {
                -0.25f, 0.5f, 0.0f,     // A 0
                0.0f, 0.25f, 0.5f,      // B 1
                -0.5f, 0.0f, 0.25f,     // C 2
                -0.25f, -0.5f, 0.0f,    // D 3
                0.25f, -0.5f, 0.0f,     // E 4
                0.0f, -0.25f, 0.5f,     // F 5
                0.5f, 0.0f, 0.25f,      // G 6
                0.5f, 0.0f, -0.25f,     // H 7 
                0.25f, 0.5f, 0.0f,      // I 8 
                0.0f, 0.25f, -0.5f,     // J 9
                -0.5f, 0.0f, -0.25f,    // K 10 
                0.0f, -0.25f, -0.5f     // L 11
        };*/

	const float a = 0.525731f;
	const float b = 0.850651f;

	const vec3 FaceCoord[12] = {
		vec3(-a, 0, b), vec3(a, 0, b), 	vec3(-a, 0, -b), vec3(a, 0, -b),
		vec3(0, b, a), 	vec3(0, b, -a), vec3(0, -b, a),  vec3(0, -b, -a),
		vec3(b, a, 0), 	vec3(-b, a, 0), vec3(b, -a, 0),  vec3(-b, -a, 0)
	};

	const int indices[20][3] = {
		{0,1,4}, {0,4,9}, {9,4,5}, {4,8,5}, {4,1,8},
		{8,1,10}, {8,10,3}, {5,8,3}, {5,3,2}, {2,3,7},
		{7,3,10}, {7,10,6}, {7,6,11}, {11,6,0}, {0,6,1},
		{6,10,1}, {9,11,0}, {9,2,11}, {9,5,2}, {7,11,2}
	};

	/*const vector<int> FaceIndex = {
                0, 1, 2,                // A, B, C  
                0, 8, 1,                // A, I, B
                1, 8, 6,                // B, I, G
                3, 2, 5,                // D, C, F ; 9, 10, 11
                3, 5, 4,
                4, 5, 6,
                2, 1, 5,
                1, 6, 5,
                10, 0, 2,
                3, 10, 2,
                6, 8, 7,
                4, 6, 7,
                9, 0, 10,
                8, 0, 9,
                7, 8, 9,
                7, 9, 11,
                9, 10, 11,
                11, 10, 3,
                4, 11, 3,
                7, 11, 4
        };*/

class Icosahedron {
private:
	//vector<Renderable2D*> sprites;
	float size = 1.0f;
	int m_depth = 1;	
	vector<Renderable2D*> sprites;
public:
	Icosahedron();
	vector<Renderable2D*> getRenderables();	
	void set_size(float size) { this->size = size; }	
	void set_depth(int depth) { this->m_depth = depth; }
        Sprite* subdivide(vec3 v1, vec3 v2, vec3 v3, int depth);
}; 


#endif






