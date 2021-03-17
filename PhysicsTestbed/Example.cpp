#include "Example.h"
#include"KinematicObject.h"
#include <vector>

Example::Example() : Testbed()
{
	//Your initialisation code goes here!
	for (int i = 0; i < 100 ; i++)
	{
		stuff.push_back(KinematicObject());
	}
	
}

void Example::Update()
{
	//This call ensures that your mouse position and aspect ratio are maintained as correct.
	Testbed::Update();
	

	//Your physics (or whatever) code goes here!
	for (int i = 0; i < stuff.size(); i++)
	{
		stuff[i].Update(deltaTime);
		for (int j = 0; j < stuff.size(); j++)
		{
			//Check if this circle is the current circle and that it hasn't already been checked for collision
			if (j == i || stuff[i].collisionCheck || !stuff[j].collisionEnabled || stuff[j].collisionCheck)
			{
				continue;
			}

			//Calculate the distance between circle i and j using the distance between two points formula
			float distanceBetween = sqrt((stuff[i].position.x - stuff[j].position.x) * (stuff[i].position.x - stuff[j].position.x) +
				(stuff[i].position.y - stuff[j].position.y) * (stuff[i].position.y - stuff[j].position.y));
			float totalRadius = stuff[i].radius + stuff[j].radius;
			//std::cout << "Circle " << i << " and " << j << " have " << totalRadius << " totalRadius and " << distanceBetween << " distanceBetween and velocity " << stuff[i].velocity.y << " , " << stuff[j].velocity.y << std::endl;
			//std::cout << '(' << stuff[i].position.x << ',' << stuff[i].position.y << ") (" << stuff[j].position.x << ',' << stuff[j].position.y << ')' << std::endl;
			if (distanceBetween <= totalRadius)
			{
				float iXInitialVelocity = stuff[i].velocity.x;
				float iYInitialVelocity = stuff[i].velocity.y;
				float jXInitialVelocity = stuff[j].velocity.x;
				float jYInitialVelocity = stuff[j].velocity.y;
				//Check if the objects are moving in different directions, making sure they are actually colliding and not stuck in each other.
				if (stuff[j].position.x < stuff[i].position.x)
				{
					if (iXInitialVelocity > 0 && jXInitialVelocity < 0)
					{
						stuff[i].collisionCheck = true;
						stuff[j].collisionCheck = true;
						continue;
					}
				}
				else
				{
					if (iXInitialVelocity < 0 && jXInitialVelocity > 0)
					{
						stuff[i].collisionCheck = true;
						stuff[j].collisionCheck = true;
						continue;
					}
				}
				if (stuff[j].position.y < stuff[i].position.y)
				{
					if (iYInitialVelocity > 0 && jXInitialVelocity < 0)
					{
						stuff[i].collisionCheck = true;
						stuff[j].collisionCheck = true;
						continue;
					}
				}
				else
				{
					if (iYInitialVelocity < 0 && jXInitialVelocity > 0)
					{
						stuff[i].collisionCheck = true;
						stuff[j].collisionCheck = true;
						continue;
					}
				}


				//boolean to stop it from doing this again later in the i for loop
				stuff[i].collisionCheck = true;
				stuff[j].collisionCheck = true;

				//stuff[i].position = stuff[i].prePosition;
				//stuff[j].position = stuff[j].prePosition;
				

				float iMass = stuff[i].radius/100;
				float jMass = stuff[j].radius/100;

				//float xinitials = jXInitialVelocity - iXInitialVelocity;
				//float yInitials = jYInitialVelocity - iYInitialVelocity;

				//Calculate final velocity using elastic collision formula
				float jXFinalVelocity = iXInitialVelocity*(iMass+iMass) / (iMass + jMass) + jXInitialVelocity*(jMass-iMass)/(iMass+jMass);
				float jYFinalVelocity = iYInitialVelocity*(iMass+iMass) / (iMass + jMass) + jYInitialVelocity*(jMass-iMass)/(iMass+jMass);

				//Trying to figure out how to move the circles when they collide so that they are no longer colliding
				//Not sure how to do this yet
				float distanceToMove = (totalRadius - distanceBetween)/4;

				stuff[j].velocity.x = jXFinalVelocity;
				stuff[j].velocity.y = jYFinalVelocity;

				stuff[i].velocity.x = jXInitialVelocity - iXInitialVelocity + jXFinalVelocity;
				stuff[i].velocity.y = jYInitialVelocity - iYInitialVelocity + jYFinalVelocity;

				//std::cout << "Circle " << i << " collided with " << j << std::endl;

				
				
			}

		}
		stuff[i].collisionCheck = false;
	}
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
				stuff[i].velocity -= 1;
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

	for (int i = 0; i < stuff.size(); i++)
	{
		
		
		lines.DrawCircle(stuff[i].position, stuff[i].radius, { 1,1,1 }, 8);
		
	}


	//Your drawing code goes here!
	


	//This call puts all the lines you've set up on screen - don't delete it or things won't work.
	Testbed::Render();
}