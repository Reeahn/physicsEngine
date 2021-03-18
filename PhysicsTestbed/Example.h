#pragma once

#include "Testbed.h"

#include <vector>
#include "KinematicObject.h"
#include "Maths.h"


class Example : public Testbed
{
protected:
	std::vector<KinematicObject> stuff;
public:

	Example();

	void Update();

	void Render();
};