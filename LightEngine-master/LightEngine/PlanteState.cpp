#include "PlanteState.h"

void IdleState::Start(PlantEntity* plant)
{
	std::cout << "Plante en mode Idle" << std::endl;
}

void IdleState::Update(PlantEntity* plant, float dt)
{
	if (plant->IsZombieInRange()) {
		plant->SetState(new ShootingState());
	}
	else {
		plant->SetState(new ReloadState());
	}
}

void ReloadState::Start(PlantEntity* plant)
{
	std::cout << "Rechargement..." << std::endl;
}

void ReloadState::Update(PlantEntity* plant, float dt)
{
	plant->SetAmmo(5);
	plant->SetState(new IdleState());
}

void ShootingState::Start(PlantEntity* plant)
{
	std::cout << "Plante tire !" << std::endl;
}

void ShootingState::Update(PlantEntity* plant, float dt)
{
	std::cout << plant->GetAmmo();
	if (plant->GetAmmo() > 0) {
		plant->Shoot();
	}
	else {
		plant->SetState(new ReloadState());
	}
}