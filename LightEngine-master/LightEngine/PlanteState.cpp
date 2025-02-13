#include "PlanteState.h"
#include "TDscene.h"

void IdleState::Start(PlantEntity* plant)
{
	std::cout << "Plante en mode Idle" << std::endl;
}

void IdleState::Update(PlantEntity* plant, float dt)
{
	if (plant->IsZombieInRange()) {
			plant->SetState(new ShootingState());
	}
	else if (plant->GetAmmo() < 5){
		plant->SetState(new ReloadState());
	}
}

void ReloadState::Start(PlantEntity* plant)
{
	std::cout << "Rechargement..." << std::endl;
}

void ReloadState::Update(PlantEntity* plant, float dt)
{
	plant->AddTimeBeforeReload(dt);
	if (plant->GetTimeBeforeReload() >= plant->GetTimeToReload()) {
		plant->SetAmmo(5);
		plant->AddTimeBeforeReload(-plant->GetTimeBeforeReload());
		plant->SetState(new IdleState());
	}
}

void ShootingState::Start(PlantEntity* plant)
{
	std::cout << "Plante tire !" << std::endl;
}

void ShootingState::Update(PlantEntity* plant, float dt)
{
	TDscene* tdScene = dynamic_cast<TDscene*>(plant->GetScene());

	plant->AddTimeBeforeShoot(dt);
	if (plant->GetAmmo() > 0 && plant->GetTimeBeforeShoot() >= plant->GetTimeToShoot()) { 
			plant->Shoot();
			plant->AddTimeBeforeShoot(-plant->GetTimeBeforeShoot());
	}
	else if (plant->GetAmmo() <= 0){
		plant->SetState(new ReloadState());
	}
	if (!plant->IsZombieInRange()) {
		plant->SetState(new IdleState());
	}
}