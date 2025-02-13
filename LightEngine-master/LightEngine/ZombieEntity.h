#pragma once
#include "Entity.h"
class ZombieEntity : public Entity
{
	int life = 2;
	float TimeBeforeInvic = 0;
public:
void OnCollision(Entity* other) override;
void OnUpdate()override;
};

