#include "TDscene.h"
#include "ZombieEntity.h"
#include "PlantEntity.h"
#include "BulletEntity.h"
#include "Debug.h"

void TDscene::OnInitialize()
{
	mZomb1 = CreateEntity<ZombieEntity>(50, sf::Color::Green);
	mZomb1->SetPosition(1100, 260);
	mZomb1->SetRigidBody(true);
	mZomb1->SetTag(1);
	mZombies.push_back(mZomb1);

	mZomb2 = CreateEntity<ZombieEntity>(50, sf::Color::Green);
	mZomb2->SetPosition(1100, 360);
	mZomb2->SetRigidBody(true);
	mZomb2->SetTag(1);
	mZombies.push_back(mZomb2);

	mZomb3 = CreateEntity<ZombieEntity>(50, sf::Color::Green);
	mZomb3->SetPosition(1100, 460);
	mZomb3->SetRigidBody(true);
	mZomb3->SetTag(1);
	mZombies.push_back(mZomb3);

	mPlant1 = CreateEntity<PlantEntity>(50, sf::Color::Yellow);
	mPlant1->SetPosition(60, 260);
	mPlant1->SetRigidBody(true);
	mPlant1->SetTag(2);

	mPlant2 = CreateEntity<PlantEntity>(50, sf::Color::Yellow);
	mPlant2->SetPosition(60, 360);
	mPlant2->SetRigidBody(true);
	mPlant2->SetTag(2);

	mPlant2 = CreateEntity<PlantEntity>(50, sf::Color::Yellow);
	mPlant2->SetPosition(60, 460);
	mPlant2->SetRigidBody(true);
	mPlant2->SetTag(2);

	pEntitySelected = nullptr;
}

void TDscene::OnEvent(const sf::Event& event)
{

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		TrySetSelectedEntity(mZomb1, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(mZomb2, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(mZomb3, event.mouseButton.x, event.mouseButton.y);

		ZombieEntity* zomb = CreateEntity<ZombieEntity>(50, sf::Color::Green);
		zomb->SetPosition(event.mouseButton.x, event.mouseButton.y);
		zomb->SetTag(1);
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
		bull->SetTag(3);
	}

	if (event.type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			ZombieEntity* zomb = CreateEntity<ZombieEntity>(50, sf::Color::Green);
			zomb->SetPosition(1100, 260);
			zomb->SetTag(1);
			mZombies.push_back(zomb);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			ZombieEntity* zomb = CreateEntity<ZombieEntity>(50, sf::Color::Green);
			zomb->SetPosition(1100, 360);
			zomb->SetTag(1);
			mZombies.push_back(zomb);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			ZombieEntity* zomb = CreateEntity<ZombieEntity>(50, sf::Color::Green);
			zomb->SetPosition(1100, 460);
			zomb->SetTag(1);
			mZombies.push_back(zomb);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			BulletEntity* bull = CreateEntity<BulletEntity>(25, sf::Color::Red);
			bull->SetPosition(160,260);
			bull->SetTag(3);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			BulletEntity* bull = CreateEntity<BulletEntity>(25, sf::Color::Red);
			bull->SetPosition(160, 360);
			bull->SetTag(3);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			BulletEntity* bull = CreateEntity<BulletEntity>(25, sf::Color::Red);
			bull->SetPosition(160, 460);
			bull->SetTag(3);
		}
	}
}

void TDscene::TrySetSelectedEntity(ZombieEntity* pEntity, int x, int y)
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
	/*------------------------------ "automatic" ----------------------------
		int rando = rand() % 100;
		if (rando == 1) {
			ZombieEntity* zomb = CreateEntity<ZombieEntity>(50, sf::Color::Green);
			zomb->SetPosition(1100, 260);
			zomb->SetTag(1);
			mZombies.push_back(zomb);
		}
		else if (rando == 2) {
			ZombieEntity* zomb = CreateEntity<ZombieEntity>(50, sf::Color::Green);
			zomb->SetPosition(1100, 360);
			zomb->SetTag(1);
			mZombies.push_back(zomb);
		}
		else if (rando == 3) {
			ZombieEntity* zomb = CreateEntity<ZombieEntity>(50, sf::Color::Green);
			zomb->SetPosition(1100, 460);
			zomb->SetTag(1);
			mZombies.push_back(zomb);
		}
		---------------------------------------------------------------------*/
}

std::vector<ZombieEntity*> TDscene::GetZombies() {
	return mZombies; 
}

int TDscene::GetZombiesSize() {
	int Size = mZombies.size();
	return Size;
}
