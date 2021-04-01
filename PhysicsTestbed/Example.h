#pragma once

#include "Testbed.h"

#include <vector>
#include "KinematicObject.h"
#incldue "RectangleObject.h"
#include "Maths.h"


class Example : public Testbed
{
protected:
	std::vector<KinematicObject> stuff;
	std::vector<Rectangle> rectangles;
public:
	int index = 0;
	int swaps = 1;
	bool sorted = true;
	
	Example();

	void Update();

	void Render();
};
