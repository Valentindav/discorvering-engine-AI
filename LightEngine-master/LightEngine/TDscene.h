#pragma once
#include "Scene.h"

class ZombieEntity;
class PlantEntity;
class TDscene : public Scene
{

	ZombieEntity* mZomb1;
	ZombieEntity* mZomb2;
	ZombieEntity* mZomb3;

	PlantEntity* mPlant1;
	PlantEntity* mPlant2;
	PlantEntity* mPlant3;

	Debug* debug;

	ZombieEntity* pEntitySelected;
	std::vector<ZombieEntity*> mZombies;   

	private:
		void TrySetSelectedEntity(ZombieEntity* pEntity, int x, int y);

	public:
		void OnInitialize() override;
		void OnEvent(const sf::Event& event) override;
		void OnUpdate() override;
		std::vector<ZombieEntity*> GetZombies();
};

