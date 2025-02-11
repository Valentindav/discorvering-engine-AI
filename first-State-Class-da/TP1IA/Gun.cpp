#include "Gun.h"
#include "StateManager.h"
#include <iostream>


Gun::Gun() {
	mCurrentState = new FullState(this);
}

Gun::~Gun() {
	delete mCurrentState;
}


bool Gun::TransitionTo(state1 newState) {
	int currentStateIndex = static_cast<int>(mState);
	int newStateIndex = static_cast<int>(newState);
	if(mTransition[currentStateIndex][newStateIndex] == 0) return false;
	mState = newState;
	return true;
}

void Gun::SetState(State* state) {
	if (mCurrentState) {
		delete mCurrentState;
	}
	mCurrentState = state;
	mCurrentState->Start(); 
}

void Gun::Update(float deltaTime) {
	mCurrentState->Update(deltaTime);
}

void Gun::Shoot() {
	SetState(new ShootingState(this));
}

void Gun::Reload() {
	SetState(new ReloadingState(this));

}

int Gun::GetAmmo() const {
	return mAmmo;
}

int Gun::GetCapacity() const {
	return mCapacity;
}

void Gun::SetAmmo(int newAmmo) {
	mAmmo = newAmmo;
	
}

float Gun::GetReloadTime() {
	return mReloadTime;
}

float Gun::GetReloadProgress() {
	return mReloadProgress;
}

float Gun::GetShootTime() {
	return mShootTime;
}

float Gun::GetShootProgress() {
	return mShootProgress;
}

float Gun::SetShootProgress(float progress) {
		mShootProgress += progress;
		return progress;
}

State* Gun::GetState() {
	return mCurrentState;
}

float Gun::SetReloadProgress(float progress) {
		mReloadProgress += progress;
		return progress;
}
void Gun::ResetShootProgress() {
	mShootProgress = 0;
}

void Gun::ResetReloadProgress() {
	mReloadProgress = 0;
}
