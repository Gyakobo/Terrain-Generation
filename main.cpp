#include "headers/main.h"

using namespace std;

const int width = 800, height = 800;

bool ico = false;

int main() {

	bool wire_frame_mode = false;

	Camera Camera(width, height, vec3(0.0f, 0.0f, 2.0f));

	Window window("Mexil", width, height);	



	GLfloat lightVertices[] = {
		-0.1f, -0.1f, 0.1f, 
		-0.1f, -0.1f, -0.1f, 
		0.1f, -0.1f, -0.1f, 
		0.1f, -0.1f, 0.1f, 
		-0.1f, 0.1f, 0.1f, 
		-0.1f, 0.1f, -0.1f, 
		0.1f, 0.1f, -0.1f, 
		0.1f, 0.1f, 0.1f, 
	};

	GLuint lightIndices[] = {
		0, 1, 2,
		0, 2, 3,
		0, 4, 7,
		0, 7, 3,
		3, 7, 6,
		3, 6, 2, 
		2, 6, 5, 
		2, 5, 1,
		1, 5, 4,
		1, 4, 0,
		4, 5, 6, 
		4, 6, 7
	};

	Shader shader("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl", "shaders/geometric_shader.glsl");
	shader.enable();
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(0.0f, 0.0f, -1.3f)));

	vec3 light_pos = vec3(0.0f, 0.0f, 0.0f);
	shader.setUniform3f("light_pos", light_pos);

	
	glViewport(0, 0, width, height);

	// Very important, do not touch
	glEnable(GL_DEPTH_TEST); // Gives us true 3d
	
	//glEnable(GL_BLEND);

	//glDisable(GL_LIGHTING);
	//glEnable(GL_POINT_SMOOTH);

	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	////////////////////////////////

//#if ico
/*	Icosahedron icosahedron;
	TileLayer layer(&shader);
	vector<Renderable2D*> IcosahedronFaces;

	for (int i=0; i<20; i++) {
                icosahedron.subdivide(FaceCoord[indices[i][0]], FaceCoord[indices[i][1]], FaceCoord[indices[i][2]], 1);
                for (int j=0; j<icosahedron.getRenderables().size(); j++)
                        IcosahedronFaces.push_back(icosahedron.getRenderables().at(j));
        }
        //cout << "Shape faces = " << IcosahedronFaces.size() << endl;
        for (int i=0; i<IcosahedronFaces.size(); i++) layer.add(IcosahedronFaces.at(i));*/
//#else
	//Terrainface terrain(2, vec3(0.0f, 1.0f, 0.0f));
	//terrain.ConstructMesh();
	//TileLayer layer(&shader);
    //for (int i=0; i<terrain.getRenderables().size(); i++) layer.add(terrain.getRenderables().at(i));
	Planet planet(2, 1.0f, 1.0f);
	TileLayer layer(&shader);
    for (int i=0; i<planet.getRenderables().size(); i++) layer.add(planet.getRenderables().at(i));
	//delete terrain;
//#endif

	float x, y, angle_y = 0.0f, angle_x = 0.0f;

	float x_m=0.0f, z_m=0.0f;

	int numb_face = 2;
	int numb_face_previous = numb_face;
	
	float roughness=0.0f, strength=0.0f;
	float roughness_previous=roughness, strength_previous=strength;

	float x_offset=0.0f, y_offset=0.0f, z_offset=0.0f;
	float x_offset_previous=x_offset, y_offset_previous=y_offset, z_offset_previous=z_offset;


//#ifdef ico
	while(!window.closed()) {
		window.clear();

		window.RenderGUI(&numb_face, &strength, &roughness, &x_offset, &y_offset, &z_offset);
		//window.RenderGUI(&numb_face);

		if (numb_face != numb_face_previous || roughness != roughness_previous || strength != strength_previous || x_offset != x_offset_previous || y_offset != y_offset_previous || z_offset != z_offset_previous) {
			Planet planet(numb_face, strength, roughness, vec3(x_offset, y_offset, z_offset));
			layer.clean_slate();
			for (int i=0; i<planet.getRenderables().size(); i++) layer.add(planet.getRenderables().at(i));
			numb_face_previous = numb_face;
			strength_previous = strength;
			roughness_previous = roughness;

			x_offset_previous = x_offset;
			y_offset_previous = y_offset;
			z_offset_previous = z_offset;
		}


		shader.enable();
		Camera.Inputs(window.getWindow()); // Low-key sad
		
		shader.enable();
		Camera.Matrix(120.0f, 0.1f, 100.0f, shader, "camMatrix");

		shader.enable();
		shader.setUniformMat4("pr_matrix", mat4::perspective(100.0f, (float)(window.getWidth()/window.getHeight()), 0.1f, 100.0f));
		shader.setUniform3f("light_pos", vec3(x_m, 0, z_m));

		if (window.isKeyPressed(GLFW_KEY_ESCAPE)) break;

		if (window.isKeyPressed(GLFW_KEY_DOWN)) angle_y		-= 2.5f;
		if (window.isKeyPressed(GLFW_KEY_UP)) angle_y		+= 2.5f;
		if (window.isKeyPressed(GLFW_KEY_LEFT)) angle_x		-= 2.5f;
		if (window.isKeyPressed(GLFW_KEY_RIGHT)) angle_x	+= 2.5f;

		
		if (window.isKeyPressed(GLFW_KEY_W)) z_m		+= 0.1f;
		if (window.isKeyPressed(GLFW_KEY_S)) z_m		-= 0.1f;
		if (window.isKeyPressed(GLFW_KEY_A)) x_m		+= 0.1f;
		if (window.isKeyPressed(GLFW_KEY_D)) x_m		-= 0.1f;
		

		if (angle_y >= 360.0f || angle_y <= -360.0f) angle_y = 0.0f;
		if (angle_x >= 360.0f || angle_x <= -360.0f) angle_x = 0.0f;

		shader.enable();	
		shader.setUniformMat4("rt_matrix_x", mat4::rotation(angle_x, vec3(0.0f, 1.0f, 0.0f)) );
		shader.setUniformMat4("rt_matrix_y", mat4::rotation(angle_y, vec3(1.0f, 0.0f, 0.0f)) );
		
		window.getMousePosition(x, y);

		shader.enable();
		layer.render();	

		window.update();
	}
/*#else
	SimplexNoise();
#endif*/


	return 0;
}
		

/*if (window.isKeyPressed(GLFW_KEY_DOWN)) angle_y		-= 2.5f;
if (window.isKeyPressed(GLFW_KEY_UP)) angle_y		+= 2.5f;

if (window.isKeyPressed(GLFW_KEY_LEFT)) angle_x		-= 2.5f;
if (window.isKeyPressed(GLFW_KEY_RIGHT)) angle_x	+= 2.5f;*/

//if (angle_y >= 360.0f || angle_y <= -360.0f) angle_y = 0.0f;
//if (angle_x >= 360.0f || angle_x <= -360.0f) angle_x = 0.0f;

//shader.setUniformMat4("ml_matrix", mat4::rotation((y+window.getHeight()/2.0f)*0.3f, vec3(1.0f, 0.0f, 0.0f)));
