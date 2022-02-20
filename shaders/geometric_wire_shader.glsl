#version 330

layout (triangles) in;
layout (line_strip, max_vertices=6) out;

//uniform vec4 colour;

in DATA {
	//vec4 color;	
	mat4 pr_matrix;
} vertex_in[];

void main(void) {
    gl_Position     = vertex_in[0].pr_matrix * gl_in[0].gl_Position;
    EmitVertex();
    gl_Position     = vertex_in[0].pr_matrix * gl_in[1].gl_Position;
    EmitVertex();
    EndPrimitive();

    gl_Position     = vertex_in[0].pr_matrix * gl_in[1].gl_Position;
    EmitVertex();
    gl_Position     = vertex_in[0].pr_matrix * gl_in[2].gl_Position;
    EmitVertex();
    EndPrimitive();

    gl_Position     = vertex_in[0].pr_matrix * gl_in[2].gl_Position;
    EmitVertex();
    gl_Position     = vertex_in[0].pr_matrix * gl_in[0].gl_Position;
    EmitVertex();
    EndPrimitive();
}




