#include "Example.h"
#include "KinematicObject.h"
#incldue "RectangleObject.h"
#include <vector>

Example::Example() : Testbed()
{
	//Your initialisation code goes here!
	for (int i = 0; i < 100 ; i++)
	{
		stuff.push_back(KinematicObject());
	}
	
	float totalWidth 10;
	float totalHeight 10;
	int rectangleAmount = 20;
	
	float rectangleWidth = totalWidth / rectangleAmount;
	float heightIncrement = totalHeight / rectangleAmount;

	for (int i = 0; i <= rectangleAmount; i++)
	{
		rectangles.push_back(RectangleObject(i, rectangleHeight, heightIncrement);
	}
	// Shuffle the rectangles up until they are in a unsorted order
	while (sorted)
	{
		for (int i = 0; i <= rectangleAmount - 1; i++)
		{
			int positionSwap = GetRandomInt(i,rectangleAmount);
			if (positionSwap == i)
				continue;
			float tempX = rectangles[i].centre.x;
			rectangles[i].centre.x = rectangles[positionSwap].centre.x;
			rectangles[positionSwap].centre.x = tempX;
		}
		for (int i = 0; i <= rectangleAmount - 1; i++) 
		{
			if (rectangles[index].centre.x > rectangles[index + 1].centre.x)
				sorted = false;
		}
	}
}

void Example::Update()
{
	//This call ensures that your mouse position and aspect ratio are maintained as correct.
	Testbed::Update();
	// if rectangles are sorted then dont sort them again
	if (!sorted)
	{
		//reset swaps and index so that we can loop through the rectangles again after hitting the last rectangle
		if (index == rectangles.size())
		{
			swaps = 0
			index = 0;
		}
		// main bubble sort algo checks if the next rectangle is smaller than the current and swaps them if so otherwise index 
		// is incremented and this check is performed again
		float tempX = rectangles[index].centre.x;
		if (rectangles[index].centre.x > rectangles[index + 1].centre.x)
		{
			rectangles[index].centre.x = rectangles[index + 1].centre.x;
			rectangles[index + 1].centre.x = tempX;
			swaps += 1;
		}
	}
	index += 1
	if (index == reectangles.size() && swaps == 0)
		sorted = true;
}

void Example::Render()
{

	//Example code that draws a blue square.
	std::vector<glm::vec2> points;
	points.push_back({ 1.5f, 1.5f });
	points.push_back({ 1.5f, 2.5f });
	points.push_back({ 2.5f, 2.5f });
	points.push_back({ 2.5f, 1.5f });

	lines.DrawRawShape((float*)points.data(), (unsigned int) points.size(), glm::vec3(0, 0, 1));


	//Example code that draws a coloured circle at the mouse position, whose colour depends on which buttons are down.
	if (leftButtonDown)
	{
		for (int i = 0; i < stuff.size(); i++) {
			
			float distanceBetween = sqrt((stuff[i].position.x - cursorPos.x) * (stuff[i].position.x - cursorPos.x) +
				(stuff[i].position.y - cursorPos.y) * (stuff[i].position.y - cursorPos.y));
			float totalRadius = stuff[i].radius + 0.2;
			if (distanceBetween <= totalRadius) {
				stuff[i].colour = { 1, 0,0 };
				storedVelocity += 1;				
			}
		}
		
		lines.DrawCircle(cursorPos, 0.2f, { 1, 0, 0 });
	}
	else if (rightButtonDown)
	{
		lines.DrawCircle(cursorPos, 0.2f, { 0, 1, 0 });
	}
	else
	{
		lines.DrawCircle(cursorPos, 0.2f, { 0, 0, 1 });
	}

	//Your drawing code goes here!
	for (int i = 0; i < rectangles.size(); i++) 
	{
		lines.DrawRectangle(rectangles[i].centre, rectangles[i].height, rectangles[i].width);
	}

	//This call puts all the lines you've set up on screen - don't delete it or things won't work.
	Testbed::Render();
}
