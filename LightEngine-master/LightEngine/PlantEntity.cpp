#include "PlantEntity.h"
#include "BulletEntity.h"
#include <iostream>

void PlantEntity::OnCollision(Entity* other)
{
	if (other->IsTag(1)) Destroy();
}

void PlantEntity::OnUpdate() {
	
}
