#pragma once
#include <time.h>
#include <iostream>
#include "State.h"

class Gun
{
	enum class state1 {
		Full,
		Loaded,
		Empty,
		Shooting,
		Reloading,

		Count
	};

	static constexpr int StateCount = static_cast<int>(state1::Count);
	state1 mState = state1::Full;

	int mTransition[StateCount][StateCount] = {
		// Full,  Loaded,  Empty,  Shooting,  Reloading
		{     0,      0 ,      0,         1,          0},//Full
		{     0,      0 ,      0,         1,          1},//Loaded
		{     0,      0 ,      0,         0,          1},//Empty
		{     0,      1 ,      1,         0,          0},//Shooting
		{     1,      0 ,      0,         0,          0},//Reloading
	};
	int mAmmo = 6, mCapacity = 6;
	float mReloadTime = 2, mShootTime = 1, mReloadProgress = 0, mShootProgress = 0;
	state1 mStateType = state1::Full;
	State* mCurrentState = nullptr;

public:
	Gun();
	~Gun();
	void Update(float deltaTime);
	void Shoot();
	void Reload();
	bool TransitionTo(state1 newState);
	int GetAmmo() const;
	int GetCapacity() const;
	void SetAmmo(int ammo);
	void SetState(State* state);
	float GetReloadTime();
	float GetReloadProgress();
	float GetShootTime();
	float GetShootProgress();
	float SetShootProgress(float progress);
	float SetReloadProgress(float progress);
	void ResetShootProgress();
	void ResetReloadProgress();
	State* GetState();
};


													

