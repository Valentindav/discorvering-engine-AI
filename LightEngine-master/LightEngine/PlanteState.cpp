#include "PlanteState.h"
#include "TDscene.h"

//--------------------------------------------------IdleState---------------------------------------
void IdleState::Start(PlantEntity* plant)
{
	std::cout << "Plante en mode Idle" << std::endl;
}

void IdleState::Update(PlantEntity* plant, float dt)
{
	TDscene* tdScene = dynamic_cast<TDscene*>(plant->GetScene());

	if (plant->IsZombieInRange()|| plant->IsZombieInAdjacent() == 1 && !plant->IsZombieInRange() || plant->IsZombieInAdjacent() == 2 && !plant->IsZombieInRange()) {
			plant->SetState(new ShootingState());
	}
	else if (plant->IsZombieInAdjacent() == 1 && !plant->IsZombieInRange()) {
		plant->SetState(new ShootingLeftState());
	}
	else if (plant->IsZombieInAdjacent() == 2 && !plant->IsZombieInRange()) {
		plant->SetState(new ShootingRightState());
	}
	else if (plant->GetAmmo() < 5){
		plant->SetState(new ReloadState());
	}
}
//----------------------------------------------------------------------------------------------------

//----------------------------------------------ReloadState-------------------------------------------
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
//----------------------------------------------------------------------------------------------------

//-------------------------------------ShootingState--------------------------------------------------
void ShootingState::Start(PlantEntity* plant)
{
	std::cout << "Plante tire !" << std::endl;
}

void ShootingState::Update(PlantEntity* plant, float dt)
{

	plant->AddTimeBeforeShoot(dt);
	if (plant->GetAmmo() > 0 && plant->GetTimeBeforeShoot() >= plant->GetTimeToShoot() && plant->IsZombieInRange()) {
			plant->Shoot();
			plant->AddTimeBeforeShoot(-plant->GetTimeBeforeShoot());
	} 
	else if (plant->GetAmmo() > 0 && plant->GetTimeBeforeShoot() >= plant->GetTimeToShoot() && plant->IsZombieInAdjacent() == 1 && !plant->IsZombieInRange()) {
		plant->ShootAdjacent(1);
		plant->AddTimeBeforeShoot(-plant->GetTimeBeforeShoot());
	}
	else if (plant->GetAmmo() > 0 && plant->GetTimeBeforeShoot() >= plant->GetTimeToShoot() && plant->IsZombieInAdjacent() == 2 && !plant->IsZombieInRange()) {
		plant->ShootAdjacent(2);
		plant->AddTimeBeforeShoot(-plant->GetTimeBeforeShoot());
	}
	else if (plant->GetAmmo() <= 0){
		plant->SetState(new ReloadState());
	}
	else if (!plant->IsZombieInRange() && plant->IsZombieInAdjacent() == -1) {
		plant->SetState(new IdleState());
	}
}
//------------------------------------------------------------------------------------------------

//------------------------------------------ShootLeft---------------------------------------------
void ShootingLeftState::Start(PlantEntity* plant)
{
	std::cout << "Plante tire a gauche !" << std::endl;
}

void ShootingLeftState::Update(PlantEntity* plant, float dt)
{

	plant->AddTimeBeforeShoot(dt);
	if (plant->IsZombieInAdjacent() == -1) {
		plant->SetState(new IdleState());
	}
	else if (plant->IsZombieInRange()) {
		plant->SetState(new ShootingState());
	}
	else if (plant->GetAmmo() > 0 && plant->GetTimeBeforeShoot() >= plant->GetTimeToShoot()) {
		plant->ShootAdjacent(1);
		plant->AddTimeBeforeShoot(-plant->GetTimeBeforeShoot());
	}
	else if (plant->GetAmmo() <= 0) {
		plant->SetState(new ReloadState());
	}
}
//-----------------------------------------------------------------------------------------------

//----------------------------------------ShootRight---------------------------------------------
void ShootingRightState::Start(PlantEntity* plant)
{
	std::cout << "Plante tire a droite !" << std::endl;
}

void ShootingRightState::Update(PlantEntity* plant, float dt)
{

	plant->AddTimeBeforeShoot(dt);
	if (plant->IsZombieInAdjacent() == -1) {
	plant->SetState(new IdleState());
	}
	else if (plant->IsZombieInRange()) {
		plant->SetState(new ShootingState());
	}
	else if (plant->GetAmmo() > 0 && plant->GetTimeBeforeShoot() >= plant->GetTimeToShoot()) {
		plant->ShootAdjacent(2);
		plant->AddTimeBeforeShoot(-plant->GetTimeBeforeShoot());
	}
	else if (plant->GetAmmo() <= 0) {
		plant->SetState(new ReloadState());
	}
}
//------------------------------------------------------------------------------------------------
