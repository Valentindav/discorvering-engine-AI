#pragma once
#include "Entity.h"
class BulletEntity : public Entity
{
	int life = 3;
	float TimeBeforeInvic = 0;
public:
	void OnCollision(Entity* other) override;
	void OnUpdate()override;
};

