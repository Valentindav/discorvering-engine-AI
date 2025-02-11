#pragma once
#include "State.h"

class FullState : public State {
public:
	FullState(Gun* gun) : State(gun) {}
	void Start() override;
	void Update(float deltaTime) override;
};

class LoadedState : public State{
public:
	LoadedState(Gun* gun) : State(gun) {}
	void Start() override;
	void Update(float deltaTime) override;
};

class EmptyState : public State{
public:
	EmptyState(Gun* gun) : State(gun) {}
	void Start() override;
	void Update(float deltaTime) override;
};

class ShootingState : public State {
public:
	ShootingState(Gun* gun) : State(gun) {}
	void Start() override;
	void Update(float deltaTime) override;
};

class ReloadingState : public State {
public:
	ReloadingState(Gun* gun) : State(gun) {}
	void Start() override;
	void Update(float deltaTime) override;
};





