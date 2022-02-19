#include "../headers/map.h"

Map::Map() {
}

vector<Renderable2D*> Map::getRenderables() {
	for (int i=0;  i<12 ; i+=3) {
		sprites.push_back( new Sprite( faces.at(i), faces.at(i+1), faces.at(i+2), vec4(0.5f, 0.5f, 0.5f, 0.5f) ));
	}

	return sprites;
}

void Map::set_size(float size) {
	this->size = size;
}


