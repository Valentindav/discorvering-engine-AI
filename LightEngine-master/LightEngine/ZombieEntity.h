#pragma once
#include "Entity.h"
class ZombieEntity : public Entity
{
public:
void OnCollision(Entity* other) override;
void OnUpdate()override;
};

