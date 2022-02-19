#version 330 core
//#extension GL_ARB_shading_language_include : require 
//#include hg_sdf.glsl 			// Doesn't work

layout (location = 0) out vec4 color;

uniform vec4 colour;

in DATA {
	vec4 position;
	vec4 color;
} fragment_in;







#define PI 3.14159265
#define TAU (2*PI)
#define PHI (sqrt(5)*0.5 + 0.5)


/*uniform vec2 u_resolution;

const float FOV		= 1.0;
const int MAX_STEPS	= 256;
const float MAX_DIST	= 500;
const float EPSILON	= 0.001;

vec2 map(vec3 p) {
	pMod3(p, vec3(5));

	// shere object
	float sphereDist	= fSphere(p, 1.0);
	float sphereID 		= 1.0;
	vec2 sphere		= vec2(sphereDist, sphereID);

	// To finalize
	vec2 res = sphere;
	return res;
}

vec2 rayMarch(vec3 ro, vec3 rd) {
	vec2 hit, object;
	for (int i=0; i < MAX_STEPS; i++) {
		vec3 p = ro + object.x * rd;
		hit = map(p);
		object.x += hit.x;
		object.y = hit.y;
		if (abs(hit.x) < EPSILON || object.x > MAX_DIST) break;	
	}
	return object;
}




void render(inout vec3 col, in vec2 uv) {
	vec3 ro = vec3(0.0, 0.0, -3.0);
	vec3 rd = normalize(vec3(uv, FOV));

	vec2 object = rayMarch(ro, rd);
	
	if (object.x < MAX_DIST) {
		col += 3.0 / object.x;
	}
}*/
 
void main() {
	/*vec2 uv = (2.0 * gl_FragCoord.xy - u_resolution.xy) / u_resolution.y;	
	vec3 col;
	render(col, uv);
	color = vec4(col, 1.0);*/
	
	//color = colour;
	color = fragment_in.color;
}









