#include "../headers/Icosahedron.h"

Icosahedron::Icosahedron() {
}

Sprite* Icosahedron::subdivide(vec3 v1, vec3 v2, vec3 v3, int depth) {
    if (depth == 0) {
	    return new Sprite(v1, v2, v3, vec4(rand()%1000/1000.0f, 0.1f, rand()%1000/1000.0f, 1));	
    }
    
	vec3 v12, v23, v31;        

	v12 = (v1 + v2);
	v23 = (v2 + v3);
	v31 = (v3 + v1);
		
	v12.x /= 2.0f;   
	v12.y /= 2.0f;   
	v12.z /= 2.0f;   
	
	v23.x /= 2.0f;   
	v23.y /= 2.0f;   
	v23.z /= 2.0f;   
	
	v31.x /= 2.0f;   
	v31.y /= 2.0f;   
	v31.z /= 2.0f;   
    
	float c = sqrt(v12.x*v12.x + v12.y*v12.y + v12.z*v12.z);
	v12.x /= c;
	v12.y /= c;
	v12.z /= c;

	c = sqrt(v23.x*v23.x + v23.y*v23.y + v23.z*v23.z);
	v23.x /= c;
	v23.y /= c;
	v23.z /= c;

	c = sqrt(v31.x*v31.x + v31.y*v31.y + v31.z*v31.z);
	v31.x /= c;
	v31.y /= c;
	v31.z /= c;

	subdivide(v1, v12, v31, depth-1);
	subdivide(v2, v23, v12, depth-1);
	subdivide(v3, v31, v23, depth-1);
	subdivide(v12, v23, v31, depth-1);
}



vector<Renderable2D*> Icosahedron::getRenderables() {
	srand(time(NULL));
	
        /*for(int i=0; i<FaceIndex.size(); i+=3) {  
                sprites.push_back(new Sprite(   vec3(FaceCoord[FaceIndex[i]*3]*size,         FaceCoord[FaceIndex[i]*3+1]*size,    FaceCoord[FaceIndex[i]*3+2]*size),
                                                vec3(FaceCoord[FaceIndex[i+1]*3]*size,       FaceCoord[FaceIndex[i+1]*3+1]*size,  FaceCoord[FaceIndex[i+1]*3+2]*size),
                                                vec3(FaceCoord[FaceIndex[i+2]*3]*size,       FaceCoord[FaceIndex[i+2]*3+1]*size,  FaceCoord[FaceIndex[i+2]*3+2]*size),
                                                vec4(rand()%1000/1000.0f, 0.1f, rand()%1000/1000.0f, 1)));
        }*/

	return sprites;
}



