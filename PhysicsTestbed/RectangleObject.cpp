#incldue "RectangleObject.h"
#include "Example.h"
#include "Maths.h"

RectangleObject::RectangleObject(int increment, float width, float heightIncrement)
{
	width = width;
	height = ( increment + 1 ) * heightIncrement;
	centre = { ( increment * width + ( increment + 1) * width ) / 2 , (( increment + 1 ) * height )/2 };
}

