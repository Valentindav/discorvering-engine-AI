#include <iostream>
#include "Gun.h"
#include <time.h>
#include <thread>
#include <conio.h>

void HandleInput(Gun* gun)
{
    //std::cout << "\nque voulez vous faire ? (s pour tirer, r pour recharger, q pour quitter) ";
    if (_kbhit() == false)
        return;

    char input = _getch();

    switch (input)
    {
    case 's':
        gun->Shoot();
        break;
    case 'r':
        gun->Reload();
        break;
    case 'q':
        exit(0);
        break;
    }
}

int main()
{
	Gun* gun = new Gun();
	bool running = true;
	float dt = 0;
    while (running)
    {
        auto start = std::chrono::high_resolution_clock::now();

		 HandleInput(gun);
		 gun->Update(dt);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;
        dt = duration.count();
    }
}


