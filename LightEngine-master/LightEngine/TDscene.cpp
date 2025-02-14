#include "TDscene.h"
#include "ZombieEntity.h"
#include "PlantEntity.h"
#include "BulletEntity.h"
#include "Debug.h"

void TDscene::OnInitialize()
{
	ZombieEntity* mZomb1 = CreateEntity<ZombieEntity>(50, sf::Color::Green);
	mZomb1->SetPosition(1100, 260);
	mZombies.push_back(mZomb1);

	ZombieEntity* mZomb2 = CreateEntity<ZombieEntity>(50, sf::Color::Green);
	mZomb2->SetPosition(1100, 360);
	mZombies.push_back(mZomb2);

	ZombieEntity* mZomb3 = CreateEntity<ZombieEntity>(50, sf::Color::Green);
	mZomb3->SetPosition(1100, 460);
	mZombies.push_back(mZomb3);

	mPlant1 = CreateEntity<PlantEntity>(50, sf::Color::Yellow);
	mPlant1->SetPosition(60, 260);

	mPlant2 = CreateEntity<PlantEntity>(50, sf::Color::Yellow);
	mPlant2->SetPosition(60, 360);

	mPlant3 = CreateEntity<PlantEntity>(50, sf::Color::Yellow);
	mPlant3->SetPosition(60, 460);

	pEntitySelected = nullptr;
}

void TDscene::OnEvent(const sf::Event& event)
{

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		TrySetSelectedEntity(mPlant1, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(mPlant2, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(mPlant3, event.mouseButton.x, event.mouseButton.y);

		ZombieEntity* zomb = CreateEntity<ZombieEntity>(50, sf::Color::Green);
		zomb->SetPosition(event.mouseButton.x, event.mouseButton.y);
		mZombies.push_back(zomb);
	}
	

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (pEntitySelected != nullptr)
		{
			pEntitySelected->GoToPosition(event.mouseButton.x, event.mouseButton.y, 100.f);
		}
		BulletEntity* bull = CreateEntity<BulletEntity>(25, sf::Color::Red);
		bull->SetPosition(event.mouseButton.x, event.mouseButton.y);
	}

	if (event.type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			ZombieEntity* zomb = CreateEntity<ZombieEntity>(50, sf::Color::Green);
			zomb->SetPosition(1100, 260);
			mZombies.push_back(zomb);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			ZombieEntity* zomb = CreateEntity<ZombieEntity>(50, sf::Color::Green);
			zomb->SetPosition(1100, 360);
			mZombies.push_back(zomb);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			ZombieEntity* zomb = CreateEntity<ZombieEntity>(50, sf::Color::Green);
			zomb->SetPosition(1100, 460);
			mZombies.push_back(zomb);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			BulletEntity* bull = CreateEntity<BulletEntity>(25, sf::Color::Red);
			bull->SetPosition(160,260);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			BulletEntity* bull = CreateEntity<BulletEntity>(25, sf::Color::Red);
			bull->SetPosition(160, 360);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			BulletEntity* bull = CreateEntity<BulletEntity>(25, sf::Color::Red);
			bull->SetPosition(160, 460);
		}
	}
}

void TDscene::TrySetSelectedEntity(Entity* pEntity, int x, int y)
{
	if (pEntity->IsInside(x, y) == false)
		return;

	pEntitySelected = pEntity;
}

void TDscene::OnUpdate()
{
	if (pEntitySelected != nullptr)
	{
		sf::Vector2f position = pEntitySelected->GetPosition();
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
	}
	debug->DrawRectangle(10, 210, 1250, 100, sf::Color::White);
	debug->DrawRectangle(10, 311, 1250, 100, sf::Color::Magenta);
	debug->DrawRectangle(10, 412, 1250, 100, sf::Color::White);
/*//	------------------------------ "automatic" ----------------------------
		int rando = rand() % 150;
		if (rando == 1) {
			ZombieEntity* zomb = CreateEntity<ZombieEntity>(50, sf::Color::Green);
			zomb->SetPosition(1100, 260);
			mZombies.push_back(zomb);
		}
		else if (rando == 2) {
			ZombieEntity* zomb = CreateEntity<ZombieEntity>(50, sf::Color::Green);
			zomb->SetPosition(1100, 360);
			mZombies.push_back(zomb);
		}
		else if (rando == 3) {
			ZombieEntity* zomb = CreateEntity<ZombieEntity>(50, sf::Color::Green);
			zomb->SetPosition(1100, 460);
			mZombies.push_back(zomb);
		}
	//	---------------------------------------------------------------------*/
}

std::vector<ZombieEntity*> TDscene::GetZombies() {
	return mZombies; 
}

int TDscene::GetZombiesSize() {
	int Size = mZombies.size();
	return Size;
}
