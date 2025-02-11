
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManager.h"
#include "SampleScene.h"
#include "TDscene.h"

#include <cstdlib>
#include <crtdbg.h>

int main() 
{
	srand(time(NULL));

    GameManager* pInstance = GameManager::Get();

	pInstance->CreateWindow(1280, 720, "Tower Defense", 60, sf::Color::Black);
	
	pInstance->LaunchScene<TDscene>();

	return 0;
}