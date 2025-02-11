#pragma once
#include "Entity.h"
class BulletEntity : public Entity
{
public:
	void OnCollision(Entity* other) override;
	void OnUpdate()override;
};

