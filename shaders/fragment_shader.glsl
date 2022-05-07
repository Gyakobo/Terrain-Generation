#version 330 core
layout (location = 0) out vec4 out_color;

in vec4 frag_color;

uniform vec3 light_pos;
uniform vec3 lightSource;
in vec3 out_normal;
in vec4 crntPos;

void main() {
	float ambient			= 0.2f;

	vec3 normal 			= normalize(out_normal);
	vec3 lightPos 			= light_pos;
	vec3 lightDirection		= normalize(lightPos + vec3(crntPos));
	float diffuse 			= max(dot(normal, lightDirection), 0.0f);

	out_color 			= frag_color * vec4(1.0f, 1.0f, 1.0f, 1.0f) * (0.589f * diffuse + ambient);
}









