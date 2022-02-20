#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 in_color;

uniform mat4 pr_matrix; 				// projection matrix
uniform mat4 vw_matrix = mat4(1.0); 	// view matrix
uniform mat4 ml_matrix = mat4(1.0); 	// model matrix
uniform mat4 rt_matrix_x = mat4(1.0); 	// rotation matrix
uniform mat4 rt_matrix_y = mat4(1.0); 	// rotation matrix

//out vec4 pos;

out DATA {
	//vec4 position; // Well kind of not needed right now
	//vec4 color;	
	mat4 pr_matrix;
} vertex_out;


void main() {
	gl_Position = ml_matrix * vw_matrix * rt_matrix_x * rt_matrix_y * position;
	
	//vertex_out.position =  ml_matrix * vw_matrix * rt_matrix_x * rt_matrix_y * position;
	//vertex_out.color = in_color; // Still deciding how to exploit this shenanegan
	vertex_out.pr_matrix = pr_matrix;
}




