#version 330 core

layout (location = 0) out vec4 color;

in vec4 frag_color;

uniform vec4 colour = vec4(1.0);

/*in DATA {
	vec4 position;
	vec4 color;
} fragment_in;*/

 
void main() {
	//color = fragment_in.color * colour;
	color = frag_color * colour;
}









