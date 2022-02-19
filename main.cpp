#include "headers/main.h"

using namespace std;

int main() {
	
	Window window("Mexil", 900, 900);	
	//glClearColor(0, 0, 0, 0);

	// perspective(float fov, float aspectRatio, float near, float far) // Reference
	mat4 pers = mat4::perspective(90.0f, window.getWidth()/window.getHeight(), 0.0f, -100.0f);

	Shader shader("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl");
	shader.enable();
	shader.setUniformMat4("pr_matrix", pers);
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(0.0f, 0.0f, -2.5f)));
	//shader.setUniform4f("colour", vec4(1, 1, 0, 1));


	glEnable(GL_DEPTH_TEST);
	// Icosahedron faces
	float FaceCoord[] = {
		-0.25f, 0.5f, 0.0f,	// A 0
		0.0f, 0.25f, 0.5f, 	// B 1
		-0.5f, 0.0f, 0.25f,	// C 2
		-0.25f, -0.5f, 0.0f, 	// D 3
		0.25f, -0.5f, 0.0f, 	// E 4
		0.0f, -0.25f, 0.5f, 	// F 5
		0.5f, 0.0f, 0.25f, 	// G 6
		0.5f, 0.0f, -0.25f,	// H 7
		0.25f, 0.5f, 0.0f, 	// I 8 
		0.0f, 0.25f, -0.5f, 	// J 9
		-0.5f, 0.0f, -0.25f, 	// K 10 
		0.0f, -0.25f, -0.5f	// L 11
	};

	for(int i=0; i<12*3; i++)
		FaceCoord[i] *= 2.0f;

	int FaceIndex[] = {
		0, 1, 2,		// A, B, C  
		0, 8, 1,		// A, I, B
		1, 8, 6,		// B, I, G
		3, 2, 5,		// D, C, F ; 9, 10, 11
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
	};

	// Remember each allusion must be taken with a +3 offset

	srand(time(NULL));

	vector<Renderable2D*> sprites;
	BatchRenderer2D renderer;


	for(int i=0; i<60; i+=3) {
		sprites.push_back(new Sprite(	vec3(FaceCoord[FaceIndex[i]*3], 	FaceCoord[FaceIndex[i]*3+1],	FaceCoord[FaceIndex[i]*3+2]), 	// D 
						vec3(FaceCoord[FaceIndex[i+1]*3], 	FaceCoord[FaceIndex[i+1]*3+1],	FaceCoord[FaceIndex[i+1]*3+2]),	// C
						vec3(FaceCoord[FaceIndex[i+2]*3], 	FaceCoord[FaceIndex[i+2]*3+1],	FaceCoord[FaceIndex[i+2]*3+2]),	// F 
						vec4(rand()%1000/1000.0f, 0.1f, rand()%1000/1000.0f, 1)));

	}



	
	float x, y, angle_y = 0.0f, angle_x = 0.0f;

	
	while(!window.closed()) {
		window.clear();

		/*if (window.isKeyPressed(GLFW_KEY_DOWN)) angle_y		-= 2.5f;
		if (window.isKeyPressed(GLFW_KEY_UP)) angle_y		+= 2.5f;

		if (window.isKeyPressed(GLFW_KEY_LEFT)) angle_x		-= 2.5f;
		if (window.isKeyPressed(GLFW_KEY_RIGHT)) angle_x	+= 2.5f;*/

		//if (angle_y >= 360.0f || angle_y <= -360.0f) angle_y = 0.0f;
		//if (angle_x >= 360.0f || angle_x <= -360.0f) angle_x = 0.0f;

		//shader.setUniformMat4("ml_matrix", mat4::rotation((y+window.getHeight()/2.0f)*0.3f, vec3(1.0f, 0.0f, 0.0f)));

		shader.setUniformMat4("rt_matrix_x", mat4::rotation(-x, vec3(0.0f, 1.0f, 0.0f)) );
		shader.setUniformMat4("rt_matrix_y", mat4::rotation(-y, vec3(1.0f, 0.0f, 0.0f)) );

		window.getMousePosition(x, y);

		//cout << "x = " << x << ", y = " << y << endl;
	
		renderer.begin();
	
		for (int i=0; i<sprites.size(); i++) renderer.submit(sprites.at(i));


		renderer.end();
		renderer.flush();

		window.update();
	}



	return 0;
}
