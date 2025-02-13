#pragma once
#include <iostream>
#include "PlantEntity.h"


class PlanteState
{
public:
	virtual void Start(PlantEntity* plant) = 0;
	virtual void Update(PlantEntity* plant, float dt) = 0;
};

class IdleState : public PlanteState
{
public:
	void Start(PlantEntity* plant) override;

	void Update(PlantEntity* plant, float dt) override;
};

class ReloadState : public PlanteState
{
public:
	void Start(PlantEntity* plant) override;

	void Update(PlantEntity* plant, float dt) override;
};

class ShootingState : public PlanteState
{
public:
	void Start(PlantEntity* plant) override;

	void Update(PlantEntity* plant, float dt) override;
};	

class ShootingRightState : public PlanteState
{
public:
	void Start(PlantEntity* plant) override;

	void Update(PlantEntity* plant, float dt) override;
};

class ShootingLeftState : public PlanteState
{
public:
	void Start(PlantEntity* plant) override;

	void Update(PlantEntity* plant, float dt) override;
};
