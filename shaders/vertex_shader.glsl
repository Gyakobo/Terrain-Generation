/*#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 in_color;
layout (location = 2) in vec3 in_normal;

uniform mat4 camMatrix = mat4(1.0);
uniform mat4 pr_matrix; 				// projection matrix
uniform mat4 vw_matrix = mat4(1.0); 	// view matrix
uniform mat4 ml_matrix = mat4(1.0); 	// model matrix
uniform mat4 rt_matrix_x = mat4(1.0); 	// rotation matrix
uniform mat4 rt_matrix_y = mat4(1.0); 	// rotation matrix

out vec4 crntPos;

out DATA {
	// Coordinate related stuff	
	vec4 color;
	mat4 projection_matrix;
	vec3 normal;

} vertex_out;

void main() {
	//gl_Position =  (ml_matrix * vw_matrix * rt_matrix_x * rt_matrix_y) * position * camMatrix * pr_matrix;
	//gl_Position =  pr_matrix * (ml_matrix * vw_matrix * rt_matrix_x * rt_matrix_y) * position;

	//crntPos = vec3(ml_matrix * vw_matrix * rt_matrix_x * rt_matrix_y * position);	

	gl_Position =  ml_matrix * vw_matrix * rt_matrix_x * rt_matrix_y * position;
	crntPos = gl_Position;

	vertex_out.color = 				in_color;
	vertex_out.normal = 			vec3(pr_matrix * ml_matrix * vw_matrix * rt_matrix_x * rt_matrix_y * vec4(in_normal, 0.0f));
	vertex_out.projection_matrix = 	pr_matrix;
	
	//frag_color = in_color; // Still deciding how to exploit this shenanegans
}*/

#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 in_color;
layout (location = 2) in vec3 in_normal;

uniform mat4 camMatrix = mat4(1.0);
uniform mat4 pr_matrix; 				// projection matrix
uniform mat4 vw_matrix = mat4(1.0); 	// view matrix
uniform mat4 ml_matrix = mat4(1.0); 	// model matrix
uniform mat4 rt_matrix_x = mat4(1.0); 	// rotation matrix
uniform mat4 rt_matrix_y = mat4(1.0); 	// rotation matrix

out vec4 crntPos;
out vec4 frag_color;
out vec3 out_normal;

void main() {
	gl_Position =  	pr_matrix * ml_matrix * vw_matrix * rt_matrix_x * rt_matrix_y * position;
	crntPos = 		ml_matrix * vw_matrix * rt_matrix_x * rt_matrix_y * position;

	frag_color = 	in_color;
	out_normal = 	vec3(pr_matrix * ml_matrix * vw_matrix * rt_matrix_x * rt_matrix_y * vec4(in_normal, 0.0f));
}