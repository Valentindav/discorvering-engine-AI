#pragma once
#include "Entity.h"


class PlanteState;
class PlantEntity : public Entity
{
private:
	const float mDetectionRange = 300.0f;
	PlanteState* mState;
	int ammo = 5;
public:
	PlantEntity();
	int GetAmmo();
	void SetAmmo(int mun);
	void SetState(PlanteState* newState);
	void OnCollision(Entity* other) override;
	void OnUpdate() override;
	void Shoot();
	bool IsZombieInRange();
};
