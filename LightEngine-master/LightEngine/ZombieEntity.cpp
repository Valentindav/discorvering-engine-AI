#include "ZombieEntity.h"
#include <iostream>

void ZombieEntity::OnCollision(Entity* other)
{
	TimeBeforeInvic -= GetDeltaTime();
	if (TimeBeforeInvic <= 0.5f) {
		life -= 1;
		TimeBeforeInvic = 1;
		if (life <= 0) {
			if (other->IsTag(3)) Destroy();
		}
	}
}

void ZombieEntity::OnUpdate() {
		GoToPosition(60, GetPosition().y, 200); // 60 = perfect
}
