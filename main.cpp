/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#include <iostream>
#include <cstring>
#include "Screen.hpp"
#include "SDL2/SDL.h"
#include <math.h>

using namespace ParticleSimulation;

int main(int argc, char ** args) {
	Screen screen;

	if (!screen.init()) {
		std::cout << "Error initializing screen" << std::endl;
	}

	bool quit = false;

	while (!quit) {
		int ellapsed = SDL_GetTicks();

		Uint8 green = (1 + sin(ellapsed * 0.001)) * 128;

		std::cout << "Now: " << (int)green << std::endl;

		for (int i = 0; i < Screen::S_HEIGHT; i++)
			for (int j = 0; j < Screen::S_WIDTH; j++)
				screen.setPixel(j, i, 0, green, 0);

		screen.update();

		if(!screen.processEvents())
			quit = true;
	}

	screen.close();

	return 0;
}
