#include "BulletEntity.h"
#include "ZombieEntity.h"
#include <iostream>

void BulletEntity::OnCollision(Entity* other)
{
	if (!other->IsTag(mTag)) Destroy();
}

void BulletEntity::OnUpdate() {
	if (GetPosition().x >= 100) {
		GoToPosition(500, GetPosition().y, 200); // 60 = perfect
	}
}
