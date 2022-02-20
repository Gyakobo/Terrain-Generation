#version 330

layout (triangles) in;
layout (triangle_strip, max_vertices=3) out;

out vec4 frag_color;

in DATA {
	vec4 color;	
	mat4 pr_matrix;
} vertex_in[];

void main(void) {
    gl_Position     = vertex_in[0].pr_matrix * gl_in[0].gl_Position;
    frag_color      = vertex_in[0].color;
    EmitVertex();

    gl_Position     = vertex_in[1].pr_matrix * gl_in[1].gl_Position;
    frag_color      = vertex_in[1].color;
    EmitVertex();
    
    gl_Position     = vertex_in[2].pr_matrix * gl_in[2].gl_Position;
    frag_color      = vertex_in[2].color;
    EmitVertex();

    EndPrimitive();
}





