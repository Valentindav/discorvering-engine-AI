#include "BulletEntity.h"
#include "ZombieEntity.h"
#include <iostream>

BulletEntity::BulletEntity() {
	SetTag(3);
}

void BulletEntity::OnCollision(Entity* other)
{
	TimeBeforeInvic -= GetDeltaTime();
	if (TimeBeforeInvic <= 0.5f) {
		life -= 1;
		TimeBeforeInvic = 1;
		if (life <= 0) {
			if (other->IsTag(1)) Destroy();
		}
	}
}

void BulletEntity::OnUpdate() {
		SetDirection(+1, 0, 200); // 60 = perfect
		if (GetPosition().x >= 1250){
			Destroy();
		}
}
