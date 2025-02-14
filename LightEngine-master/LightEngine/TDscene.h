#pragma once
#include "Scene.h"

class ZombieEntity;
class PlantEntity;
class TDscene : public Scene
{

	PlantEntity* mPlant1;
	PlantEntity* mPlant2;
	PlantEntity* mPlant3;

	Debug* debug;

	Entity* pEntitySelected;
	std::vector<ZombieEntity*> mZombies;   

	private:
		void TrySetSelectedEntity(Entity* pEntity, int x, int y);

	public:
		void OnInitialize() override;
		void OnEvent(const sf::Event& event) override;
		void OnUpdate() override;
		std::vector<ZombieEntity*> GetZombies();
		int GetZombiesSize();
};

