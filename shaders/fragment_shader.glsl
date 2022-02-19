#version 330 core
#define PI 3.14159265
#define TAU (2*PI)
#define PHI (sqrt(5)*0.5 + 0.5)

layout (location = 0) out vec4 color;

uniform vec4 colour = vec4(1.0);

in DATA {
	vec4 position;
	vec4 color;
} fragment_in;


 
void main() {
	/*vec4 fragColor = fragment_in.color;
	fragColor.a = 0.3;
	color = fragColor;*/
	color = fragment_in.color * colour;
}









