#pragma once
#include "Entity.h"


class PlanteState;
class PlantEntity : public Entity
{
private:
	const float TimeToShoot = 1;
	float TimeBeforeShoot;
	const float TimeToReload = 2;
	float TimeBeforeReload;
	const float mDetectionRange = 700.f;
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
	void AddTimeBeforeShoot(float time);
	float GetTimeToShoot();
	float GetTimeBeforeShoot();
	void AddTimeBeforeReload(float time);
	float GetTimeToReload();
	float GetTimeBeforeReload();
};
