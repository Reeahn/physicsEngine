#pragma once
#include "Maths.h"

class RectangleObject
{

public:
	glm::vec2 centre;
	float height;
	float width;
	
	RectangleObject(int increment, float width, float height);

};
