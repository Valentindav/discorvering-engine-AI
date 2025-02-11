#include "PlantEntity.h"
#include "BulletEntity.h"
#include <iostream>

void PlantEntity::OnCollision(Entity* other)
{
	if (other->IsTag(1)) Destroy();
}

void PlantEntity::OnUpdate() {
	/*int rando = rand() % 50;
	if (rando == 1) {
		BulletEntity* bull = CreateEntity<BulletEntity>(25, sf::Color::Red);
		bull->SetPosition(GetPosition().x + 100, GetPosition().y);
		bull->SetTag(3);
	}*/
}
