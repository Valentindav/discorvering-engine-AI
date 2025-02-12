#pragma once
#include <iostream>
#include "PlantEntity.h"


class PlanteState
{
public:
	virtual void Start(PlantEntity* plant) = 0;
	virtual void Update(PlantEntity* plant, float dt) = 0;
};

class ShootingState;
class ReloadState;
class IdleState : public PlanteState
{
public:
	void Start(PlantEntity* plant) override
	{
		std::cout << "Plante en mode Idle" << std::endl;
	}

	void Update(PlantEntity* plant, float dt) override
	{
		if (plant->IsZombieInRange()) {
			plant->SetState(new ShootingState());
		}
		else {
			plant->SetState(new ReloadState());
		}
	}
};

class ReloadState : public PlanteState
{
public:
	void Start(PlantEntity* plant) override
	{
		std::cout << "Rechargement..." << std::endl;
	}

	void Update(PlantEntity* plant, float dt) override
	{
		plant->SetAmmo(5);
		plant->SetState(new IdleState());
	}
};

class ShootingState : public PlanteState
{
public:
	void Start(PlantEntity* plant) override
	{
		std::cout << "Plante tire !" << std::endl;
	}

	void Update(PlantEntity* plant, float dt) override
	{
		std::cout << plant->GetAmmo();
		if (plant->GetAmmo() > 0) {
			plant->Shoot();
		}
		else {
			plant->SetState(new ReloadState());
		}
	}
};	



