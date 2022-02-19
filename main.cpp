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


	//vector<Renderable2D*> sprites;
	BatchRenderer2D renderer;

	Icosahedron shape;
	shape.set_size(2.0f);
	vector<Renderable2D*> sprites = shape.getRenderables();


	float x, y, angle_y = 0.0f, angle_x = 0.0f;

	//window.SetWireFrame(true);	
	while(!window.closed()) {
		window.clear();

		if (window.isKeyPressed(GLFW_KEY_DOWN)) angle_y		-= 2.5f;
		if (window.isKeyPressed(GLFW_KEY_UP)) angle_y		+= 2.5f;

		if (window.isKeyPressed(GLFW_KEY_LEFT)) angle_x		-= 2.5f;
		if (window.isKeyPressed(GLFW_KEY_RIGHT)) angle_x	+= 2.5f;

		if (angle_y >= 360.0f || angle_y <= -360.0f) angle_y = 0.0f;
		if (angle_x >= 360.0f || angle_x <= -360.0f) angle_x = 0.0f;

		shader.setUniformMat4("rt_matrix_x", mat4::rotation(angle_x, vec3(0.0f, 1.0f, 0.0f)) );
		shader.setUniformMat4("rt_matrix_y", mat4::rotation(angle_y, vec3(1.0f, 0.0f, 0.0f)) );

		window.getMousePosition(x, y);

		renderer.begin();
	
		for (int i=0; i<sprites.size(); i++) renderer.submit(sprites.at(i));


		renderer.end();
		renderer.flush();

		window.update();
	}



	return 0;
}
		

/*if (window.isKeyPressed(GLFW_KEY_DOWN)) angle_y		-= 2.5f;
if (window.isKeyPressed(GLFW_KEY_UP)) angle_y		+= 2.5f;

if (window.isKeyPressed(GLFW_KEY_LEFT)) angle_x		-= 2.5f;
if (window.isKeyPressed(GLFW_KEY_RIGHT)) angle_x	+= 2.5f;*/

//if (angle_y >= 360.0f || angle_y <= -360.0f) angle_y = 0.0f;
//if (angle_x >= 360.0f || angle_x <= -360.0f) angle_x = 0.0f;

//shader.setUniformMat4("ml_matrix", mat4::rotation((y+window.getHeight()/2.0f)*0.3f, vec3(1.0f, 0.0f, 0.0f)));
