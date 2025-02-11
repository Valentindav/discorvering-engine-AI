#include "StateManager.h"
#include "Gun.h"
#include <iostream>

//----------------------------------------FullState-----------------------------

void FullState::Start() {
	std::cout << "\nL arme est pleine ";
}

void FullState::Update(float deltaTime) {
	
}
//------------------------------------------------------------------------------

//----------------------------------------LoadedState---------------------------
void LoadedState::Start() {
	std::cout << "\nL arme n'est plus pleine ";
}

void LoadedState::Update(float deltaTime) {

}
//------------------------------------------------------------------------------

//----------------------------------------EmptyState----------------------------
void EmptyState::Start() {
	std::cout << "\nle joueur n'a plus de balle !";
}

void EmptyState::Update(float deltaTime) {
	gun->SetState(new ReloadingState(gun));
}
//------------------------------------------------------------------------------

//----------------------------------------ShootingState-------------------------
void ShootingState::Start() {
	gun->SetAmmo(gun->GetAmmo() - 1);
	std::cout << "\n le joueur tire, Munitions restantes : " << gun->GetAmmo();
}

void ShootingState::Update(float deltaTime) {
	gun->SetShootProgress(deltaTime);
	if (gun->GetShootProgress() >= gun->GetShootTime()) {
		gun->ResetShootProgress();

		if (gun->GetAmmo() > 0) {
			gun->SetState(new LoadedState(gun)); 
		}
		else {
			gun->SetState(new EmptyState(gun)); 
		}
	}
}
//------------------------------------------------------------------------------

//----------------------------------------ReloadingState------------------------
void ReloadingState::Start() {
	std::cout << "\nle joueur recharge";
}

void ReloadingState::Update(float deltaTime) {
		gun->SetReloadProgress(deltaTime);
		if (gun->GetReloadProgress() >= gun->GetReloadTime()) {
			gun->SetAmmo(gun->GetCapacity());
			std::cout << "\nLe joueur a rechargé et a maintenant " << gun->GetAmmo() << " balles.";

			gun->ResetReloadProgress();
			gun->SetState(new FullState(gun));
		}
}
//------------------------------------------------------------------------------