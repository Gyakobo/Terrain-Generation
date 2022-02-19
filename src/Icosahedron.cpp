#include "../headers/Icosahedron.h"

Icosahedron::Icosahedron() {
}

vector<Renderable2D*> Icosahedron::getRenderables() {
	srand(time(NULL));
	
        for(int i=0; i<60; i+=3) {  
                sprites.push_back(new Sprite(   vec3(FaceCoord[FaceIndex[i]*3]*size,         FaceCoord[FaceIndex[i]*3+1]*size,    FaceCoord[FaceIndex[i]*3+2]*size),
                                                vec3(FaceCoord[FaceIndex[i+1]*3]*size,       FaceCoord[FaceIndex[i+1]*3+1]*size,  FaceCoord[FaceIndex[i+1]*3+2]*size),
                                                vec3(FaceCoord[FaceIndex[i+2]*3]*size,       FaceCoord[FaceIndex[i+2]*3+1]*size,  FaceCoord[FaceIndex[i+2]*3+2]*size),
                                                vec4(rand()%1000/1000.0f, 0.1f, rand()%1000/1000.0f, 1)));
        }

	return sprites;
}

void Icosahedron::set_size(float size) {
	this->size = size;
}



