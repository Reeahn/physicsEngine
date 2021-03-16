#pragma once
#include "Maths.h"

class KinematicObject
{

public:
	glm::vec2 position{ 0 , 0 };
	glm::vec2 prePosition{ 0 , 0 };
	glm::vec2 velocity{ 0,0 };
	glm::vec2 acceleration{ 0, -10 };
	glm::vec2 gravity{ 0, -9.81};

	// f=m/a
	//


	float radius ;

	float force = 0.0f;
	float mass = 1.0f;

	bool collisionCheck = false;
	bool collisionEnabled = false;

	int collisonSpawnTimer = 0;

	KinematicObject();
	KinematicObject(float xPos, float yPos);

	void Update(float deltaTime);

	void CollisionCheck(glm::vec2 unitPos, float radius);

	void Randomise();



};