#ifndef TERRAINFACE_H
#define TERRAINFACE_H

#include <iostream> 
#include <stdio.h>

#include <math.h>
#include <vector>
#include "Renderable2D.h" 
#include "sprite.h" 
#include "vec2.h"
#include "vec3.h"

#include "SimplexNoise.h"
#include <cstdint>

float SimplexNoise(float x, float y, float z) {
    float noise = SimplexNoise::noise(x, y, z);
    (void)noise;
    return noise;
}

class Terrainface{
private:
    int     resolution;
    vec3    localUp;
    vec3    axisA;
    vec3    axisB;

    float   strength    = 0.0f; 
    float   roughness   = 0.0f; 
    vec3    centre      = vec3(0.0f, 0.0f, 0.0f); 

    // So we basically play with this toys: 
    int     numLayers   = 1;
    float   persistence = 0.5f;
    float   baseRoughness = 1.0f;

    vector<Renderable2D*> sprites;


public:
    Terrainface(int resolution, vec3 localUp, float strength, float roughness, vec3 centre) {
        this->resolution    = resolution;
        this->localUp       = localUp;
        this->roughness     = roughness;
        this->strength      = strength;
        this->centre        = centre;

        axisA = vec3(localUp.y, localUp.z, localUp.x);
        axisB = vec3::CrossProduct(localUp, axisA);

        sprites = {};
        srand(time(NULL));
    }

    void ConstructMesh() {
        vec3 vertices[resolution * resolution];  
        int triangles[(resolution-1) * (resolution-1) * 6]; 
        int triIndex = 0;

        for (int y=0; y<resolution; y++) {
            for (int x=0; x<resolution; x++) {
                int i = x+y*resolution;
                
                vec2 percent = vec2(x*1.0f/(resolution-1), y*1.0f/(resolution-1));
                vec3 pointOnUnitCube = localUp + vec3::multiply((percent.x-0.5f)*2.0f, axisA) + vec3::multiply((percent.y-0.5f)*2.0f, axisB); 
                vec3 pointOnUnitSphere = vec3::normalize(pointOnUnitCube);

                vertices[i] = pointOnUnitSphere;

                if((x != (resolution-1)) && (y != (resolution-1))) {
                    triangles[triIndex] =       i;
                    triangles[triIndex+1] =     i+resolution+1;
                    triangles[triIndex+2] =     i+resolution;
                    

                    triangles[triIndex+3] =     i;
                    triangles[triIndex+4] =     i+1;
                    triangles[triIndex+5] =     i+resolution+1;
                    triIndex += 6;
        
                } 
            }
        }

        for(int i=0; i < sizeof(triangles) / sizeof(triangles[0]); i+=3) {
            float offset = roughness;
            float elevation = 1.0f;
            
            // Ocluded faces
            elevation = SimplexNoise(vertices[triangles[i]].x*offset + centre.x, vertices[triangles[i]].y*offset + centre.y, vertices[triangles[i]].z*offset + centre.z);
            elevation += 1.0f;
            elevation /= 2.0f;
            elevation *= strength;
            vec3 point1 = vec3(vertices[triangles[i]].x, vertices[triangles[i]].y, vertices[triangles[i]].z) * (1+elevation);
            
            elevation = SimplexNoise(vertices[triangles[i+1]].x*offset + centre.x, vertices[triangles[i+1]].y*offset + centre.y, vertices[triangles[i+1]].z*offset + centre.z);
            elevation += 1.0f;
            elevation /= 2.0f;
            elevation *= strength;
            vec3 point2 = vec3(vertices[triangles[i+1]].x, vertices[triangles[i+1]].y, vertices[triangles[i+1]].z) * (1+elevation);
            
            elevation = SimplexNoise(vertices[triangles[i+2]].x*offset + centre.x, vertices[triangles[i+2]].y*offset + centre.y, vertices[triangles[i+2]].z*offset + centre.z);
            elevation += 1.0f;
            elevation /= 2.0f;
            elevation *= strength;
            vec3 point3 = vec3(vertices[triangles[i+2]].x, vertices[triangles[i+2]].y, vertices[triangles[i+2]].z) * (1+elevation);
            
            sprites.push_back(new Sprite(point1, point2, point3, vec4(1.0f, 1.0f, 1.0f, 1.0f)));

            /*elevation = 0.0f;
            float frequency = baseRoughness;
            float amplitude = 1;

            for (int i=0; i<numLayers; i++) {
                float v = SimplexNoise(vertices[triangles[i]].x*frequency + centre.x, vertices[triangles[i]].y*frequency + centre.y, vertices[triangles[i]].z*frequency + centre.z);
                elevation += (v+1) * 0.5f * amplitude;
                frequency *= roughness;
                amplitude *= persistence;
            }

            elevation = elevation * strength;
            vec3 point1 = vec3(vertices[triangles[i]].x, vertices[triangles[i]].y, vertices[triangles[i]].z) * (1+elevation);





            elevation = 0.0f;
            frequency = baseRoughness;
            amplitude = 1;

            for (int i=0; i<numLayers; i++) {
                float v = SimplexNoise(vertices[triangles[i+1]].x*frequency + centre.x, vertices[triangles[i+1]].y*frequency + centre.y, vertices[triangles[i+1]].z*frequency + centre.z);
                elevation += (v+1) * 0.5f * amplitude;
                frequency *= roughness;
                amplitude *= persistence;
            }

            elevation = elevation * strength;
            vec3 point2 = vec3(vertices[triangles[i+1]].x, vertices[triangles[i+1]].y, vertices[triangles[i+1]].z) * (1+elevation);




            elevation = 0.0f;
            frequency = baseRoughness;
            amplitude = 1;

            for (int i=0; i<numLayers; i++) {
                float v = SimplexNoise(vertices[triangles[i+2]].x*frequency + centre.x, vertices[triangles[i+2]].y*frequency + centre.y, vertices[triangles[i+2]].z*frequency + centre.z);
                elevation += (v+1) * 0.5f * amplitude;
                frequency *= roughness;
                amplitude *= persistence;
            }

            elevation = elevation * strength;
            vec3 point3 = vec3(vertices[triangles[i+2]].x, vertices[triangles[i+2]].y, vertices[triangles[i+2]].z) * (1+elevation);
            
            sprites.push_back(new Sprite(point1, point2, point3, vec4(1.0f, 1.0f, 1.0f, 1.0f)));*/
        }
        /* 
        // C# implementation
        mesh.Clear(); // Clears the previous data
        mesh.vertices =             vertices; 
        mesh.triangles =            triangles; 
        mesh.RecalculateNormals(); 
        */
    }

    vector<Renderable2D*> getRenderables() {
        return sprites;
    }
    
};


#endif






