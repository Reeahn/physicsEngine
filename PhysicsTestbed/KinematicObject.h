#pragma once
#include "Maths.h"

class KinematicObject
{

public:
	glm::vec2 position{ 0 , 0 };
	glm::vec2 velocity{ 0,0 };
	glm::vec2 acceleration{ 0, 0 };
	glm::vec3 colour{ 1, 1, 1 };

	// f=m/a

	float radius;
	float mass = 1.0f;

	bool collisionCheck = false;
	bool collisionEnabled = false;

	int collisonSpawnTimer = 120;

	KinematicObject();
	KinematicObject(float xPos, float yPos);

	void Update(float deltaTime);

	void CollisionCheck(glm::vec2 unitPos, float radius);

	void Randomise();



};