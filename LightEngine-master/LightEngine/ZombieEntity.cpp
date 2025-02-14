#include "ZombieEntity.h"
#include <iostream>

ZombieEntity::ZombieEntity() {
	SetTag(1);
}

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
		SetDirection(-1, 0, 200); // 60 = perfect
		if (GetPosition().x <= 60) {
			GoToPosition(60, GetPosition().y, 200);
		}
}
