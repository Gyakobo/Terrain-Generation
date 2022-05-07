#ifndef ICOSAHEDRON_H
#define ICOSAHEDRON_H

#include <iostream>
#include <stdio.h>
#include <math.h>

#include <vector>
#include "Renderable2D.h"
#include "sprite.h"


using namespace std;

class Icosahedron {
private:
        vec4 color_a = vec4(0, 200, 214, 255);
        vec4 color_b = vec4(216, 240, 242, 255);

        //vector<Renderable2D*> sprites;
        float size = 1.0f;
        vector<Renderable2D*> sprites;
public:
        Icosahedron();
        vector<Renderable2D*> getRenderables();

        void set_size(float size) { this->size = size; }
        //void set_depth(int depth) { this->depth = depth; }

        Sprite* subdivide(vec3 v1, vec3 v2, vec3 v3, int depth);

private:
        void m_subdivide(vec3 v1, vec3 v2, vec3 v3, int m_depth);
};


#endif
