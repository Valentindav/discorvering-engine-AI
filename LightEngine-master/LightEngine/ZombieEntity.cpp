#include "ZombieEntity.h"
#include <iostream>

void ZombieEntity::OnCollision(Entity* other)
{
	if (other->IsTag(3)) Destroy();
}

void ZombieEntity::OnUpdate() {
		GoToPosition(60, GetPosition().y, 200); // 60 = perfect
}
