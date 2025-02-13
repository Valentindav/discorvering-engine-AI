#include "PlantEntity.h"
#include "BulletEntity.h"
#include "ZombieEntity.h"
#include "TDscene.h"
#include "PlanteState.h"
#include <iostream>

PlantEntity::PlantEntity() {
    mState = new IdleState();
}

void PlantEntity::OnCollision(Entity* other)
{
    if (other->IsTag(1)) Destroy();
}

void PlantEntity::SetState(PlanteState* newState) {
    delete mState;
    mState = newState;
    mState->Start(this);
}

void PlantEntity::OnUpdate() {
    mState->Update(this, GetDeltaTime());
}

void PlantEntity::Shoot() {
    BulletEntity* bullet = CreateEntity<BulletEntity>(25, sf::Color::Red);
    bullet->SetPosition(GetPosition().x + 100, GetPosition().y);
    bullet->SetTag(3);
    ammo -= 1;
}

bool PlantEntity::IsZombieInRange() {
    TDscene* tdScene = dynamic_cast<TDscene*>(GetScene());
    if (tdScene) {
        std::vector<ZombieEntity*> zombies = tdScene->GetZombies();

        for (ZombieEntity* zombie : zombies) {
            float distance = zombie->GetPosition().x - this->GetPosition().x;
            if (distance <= mDetectionRange && zombie->GetPosition().y == this->GetPosition().y) {
                return true;
            }
        }
    }
    return false;
}

int PlantEntity::GetAmmo() {
    return ammo;
}

void PlantEntity::SetAmmo(int mun) {
    ammo = mun;
}

void PlantEntity::AddTimeBeforeShoot(float time) {
    TimeBeforeShoot += time;
}

float PlantEntity::GetTimeToShoot() {
    return TimeToShoot;
}

float PlantEntity::GetTimeBeforeShoot() {
    return TimeBeforeShoot;
}

void PlantEntity::AddTimeBeforeReload(float time) {
    TimeBeforeReload += time;
}

float PlantEntity::GetTimeToReload() {
    return TimeToReload;
}

float PlantEntity::GetTimeBeforeReload() {
    return TimeBeforeReload;
}