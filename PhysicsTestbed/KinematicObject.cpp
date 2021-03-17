#include "KinematicObject.h"




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
	
	CollisionCheck(position, radius);
	

	/*std::cout << " " << position.x << ", " <<position.y << std::endl;*/
	prePosition = position;
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


	if (position.y - radius < -10)
	{
		position.y = radius - 10;
	}
	if (position.y + radius > 10)
	{
		position.y = 10 -radius;
	}
	if (position.x - radius < -10)
	{
		position.x = radius - 10;
	}
	if (position.x + radius > 10)
	{
		position.x = 10 - radius;
	}


}


void KinematicObject::CollisionCheck(glm::vec2 unitPos, float radius)
{
	if (unitPos.y - radius <= -10)
	{
		velocity.y *= -1;
	}
	if (unitPos.y + radius >= 10)
	{
		velocity.y *= -1;
	}

	if (unitPos.x - radius <= -10)
	{
		velocity.x *= -1;
	}
	if (unitPos.x + radius >= 10)
	{
		velocity.x *= -1;
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
	velocity.x = GetRandomFloat(-10.0f, 10.0f);
	velocity.y = GetRandomFloat(-10.0f, 10.0f);
	radius = GetRandomFloat(0.1f, 0.5f);
	//randomise mass 
}