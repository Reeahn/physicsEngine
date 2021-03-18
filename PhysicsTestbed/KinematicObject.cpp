#include "KinematicObject.h"
#include "Example.h"





KinematicObject::KinematicObject()
{
	Randomise();
}

KinematicObject::KinematicObject(float xPos, float yPos)
{

	position.x = xPos;
	position.y = yPos;

}

void KinematicObject::Update(float deltaTime)
{
	//glm::vec2 gravityForce = glm::vec2(0.0f, -9.81f) * mass;
	
	colour = { 1, 1, 1 };

	CollisionCheck(position, radius);

	/*std::cout << " " << position.x << ", " <<position.y << std::endl;*/
	velocity += acceleration * deltaTime;
	position += velocity * deltaTime;
	
	if (!collisionEnabled)
	{
		collisonSpawnTimer += 1;
		if (collisonSpawnTimer >= 120)
		{
			collisionEnabled = true;
		}
	}
	float posX = Example::stuff[0];
}


void KinematicObject::CollisionCheck(glm::vec2 unitPos, float radius)
{
	if (unitPos.y - radius <= -10)
	{
		velocity.y *= -1;
		position.y = radius - 10;
	}
	if (unitPos.y + radius >= 10)
	{
		velocity.y *= -1;
		position.y = 10 - radius;
	}

	if (unitPos.x - radius <= -10)
	{
		velocity.x *= -1;
		position.x = radius - 10;
	}
	if (unitPos.x + radius >= 10)
	{
		velocity.x *= -1;
		position.x = 10 - radius;
	}
}


float GetRandomFloat(float min, float max)
{
	return (rand() / (float)RAND_MAX) * (max - min) + min;
}

void KinematicObject::Randomise()
{
	position.x = GetRandomFloat(-10.0f, 10.0f);
	position.y = GetRandomFloat(-10.0f, 10.0f);
	velocity.x = GetRandomFloat(-1.0f, 1.0f);
	velocity.y = GetRandomFloat(-1.0f, 1.0f);
	radius = GetRandomFloat(0.5f, 0.5f);
	//randomise mass 
}