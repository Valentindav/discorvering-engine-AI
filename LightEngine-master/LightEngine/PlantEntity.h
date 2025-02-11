#pragma once
#include "Entity.h"
class PlantEntity : public Entity
{
public:
	void OnCollision(Entity* other) override;
    void OnUpdate()override;
};

