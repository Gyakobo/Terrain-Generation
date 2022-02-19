#include "headers/main.h"

using namespace std;

int main() {

	bool wire_frame_mode = false;
	
	Window window("Mexil", 900, 900);	

	// perspective(float fov, float aspectRatio, float near, float far) // Reference
	//mat4 pers = mat4::perspective(120.0f, window.getWidth()/window.getHeight(), 0.0f, -100.0f);

	Shader shader("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl");
	shader.enable();
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(0.0f, 0.35f, -4.5f)));

	Shader mapShader("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl");
	mapShader.enable();
	mapShader.setUniformMat4("ml_matrix", mat4::translation(vec3(0.3f, -0.6f, -0.1f)));
	
	// Very important, do not touch
	glEnable(GL_DEPTH_TEST); // Gives us true 3d
	
	glDisable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDisable(GL_LIGHTING);

	glEnable(GL_POINT_SMOOTH);
	////////////////////////////////


	Icosahedron icosahedron;
	Icosahedron icosahedron1;
	Map sample_map;
	
	// First object with "shader"
	TileLayer layer(&shader);
	icosahedron.set_size(4.5f);
	vector<Renderable2D*> IcosahedronFaces = icosahedron.getRenderables();
	for (int i=0; i<IcosahedronFaces.size(); i++) layer.add(IcosahedronFaces.at(i));
	////////////////////////////


	// Second object with "shader2"
	TileLayer mapLayer(&mapShader);
	vector<Renderable2D*> mapFaces = sample_map.getRenderables();
	for (int i=0; i<mapFaces.size(); i++) mapLayer.add(mapFaces.at(i));
	////////////////////////////

	float x, y, angle_y = 0.0f, angle_x = 0.0f;

	while(!window.closed()) {
		window.clear();

		shader.enable();

		if (window.isKeyPressed(GLFW_KEY_DOWN)) angle_y		-= 2.5f;
		if (window.isKeyPressed(GLFW_KEY_UP)) angle_y		+= 2.5f;

		if (window.isKeyPressed(GLFW_KEY_LEFT)) angle_x		-= 2.5f;
		if (window.isKeyPressed(GLFW_KEY_RIGHT)) angle_x	+= 2.5f;

		if (angle_y >= 360.0f || angle_y <= -360.0f) angle_y = 0.0f;
		if (angle_x >= 360.0f || angle_x <= -360.0f) angle_x = 0.0f;

		if (window.isKeyPressed(GLFW_KEY_W)) {
			window.SetWireFrame(true);	
			shader.setUniform4f("colour", vec4(1, 1, 1, 0.3f));
			//shader.setUniform1f("transparency", 0.0);
		}
		if (window.isKeyPressed(GLFW_KEY_E)) {
			window.SetWireFrame(false);	
			shader.setUniform4f("colour", vec4(1, 1, 1, 1));
			//shader.setUniform1f("transparency", 1.0);
		}
		
		shader.setUniformMat4("rt_matrix_x", mat4::rotation(angle_x, vec3(0.0f, 1.0f, 0.0f)) );
		shader.setUniformMat4("rt_matrix_y", mat4::rotation(angle_y, vec3(1.0f, 0.0f, 0.0f)) );

		window.getMousePosition(x, y);

		layer.render();	
		mapLayer.render();

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
