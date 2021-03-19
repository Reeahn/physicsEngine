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
	colour = { 1,1,1 };
	//glm::vec2 gravityForce = glm::vec2(0.0f, -9.81f) * mass;
	
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
	

	if (position.y - radius <= -width)
	{
		position.y = radius - width;
	}
	if (position.y + radius >= width)
	{
		position.y = width -radius;
	}
	if (position.x - radius <= -width)
	{
		position.x = radius - width;
	}
	if (position.x + radius >= width)
	{
		position.x = width - radius;
	}


}


void KinematicObject::CollisionCheck(glm::vec2 unitPos, float radius)
{
	if (unitPos.y - radius <= -width)
	{
		velocity.y *= -1;
	}
	if (unitPos.y + radius >= width)
	{
		velocity.y *= -1;
	}

	if (unitPos.x - radius <= -width)
	{
		velocity.x *= -1;
	}
	if (unitPos.x + radius >= width)
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
	position.x = GetRandomFloat(-5.0f, 5.0f);
	position.y = GetRandomFloat(-5.0f, 5.0f);
	velocity.x = GetRandomFloat(-1.0f, 1.0f);
	velocity.y = GetRandomFloat(-1.0f, 1.0f);
	radius = GetRandomFloat(0.1f, 0.5f);
	//randomise mass 
}