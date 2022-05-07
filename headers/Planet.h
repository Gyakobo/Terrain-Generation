#ifndef PLANET_H
#define PLANET_H

#include <iostream> 
#include <stdio.h>

#include <math.h>
#include <vector>
#include "Renderable2D.h" 
#include "sprite.h" 
#include "vec2.h"
#include "vec3.h"
#include "TerrainFace.h"

class Planet {
private:
    vector<Renderable2D*> sprites;

public:
    Planet(int resolution=2, float strength=0.0f, float roughness=0.0f, vec3 centre = vec3(0.0f, 0.0f, 0.0f)) {
        Terrainface terrain1(resolution, vec3(0.0f, 1.0f, 0.0f), strength, roughness, centre);
        Terrainface terrain2(resolution, vec3(0.0f, -1.0f, 0.0f), strength, roughness, centre);
        Terrainface terrain3(resolution, vec3(1.0f, 0.0f, 0.0f), strength, roughness, centre);
        Terrainface terrain4(resolution, vec3(-1.0f, 0.0f, 0.0f), strength, roughness, centre);
        Terrainface terrain5(resolution, vec3(0.0f, 0.0f, 1.0f), strength, roughness, centre);
        Terrainface terrain6(resolution, vec3(0.0f, 0.0f, -1.0f), strength, roughness, centre);
	    terrain1.ConstructMesh();
	    terrain2.ConstructMesh();
	    terrain3.ConstructMesh();
	    terrain4.ConstructMesh();
	    terrain5.ConstructMesh();
	    terrain6.ConstructMesh();

        for (int i=0; i<terrain1.getRenderables().size(); i++) sprites.push_back(terrain1.getRenderables().at(i));
        for (int i=0; i<terrain2.getRenderables().size(); i++) sprites.push_back(terrain2.getRenderables().at(i));
        for (int i=0; i<terrain3.getRenderables().size(); i++) sprites.push_back(terrain3.getRenderables().at(i));
        for (int i=0; i<terrain4.getRenderables().size(); i++) sprites.push_back(terrain4.getRenderables().at(i));
        for (int i=0; i<terrain5.getRenderables().size(); i++) sprites.push_back(terrain5.getRenderables().at(i));
        for (int i=0; i<terrain6.getRenderables().size(); i++) sprites.push_back(terrain6.getRenderables().at(i));
    }


    vector<Renderable2D*> getRenderables() {
        return sprites;
    }


};


#endif
