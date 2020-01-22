/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#include <iostream>
#include <cstring>
#include "Screen.h"
#include "SDL2/SDL.h"

using namespace ParticleSimulation;

int main(int argc, char ** args) {
	Screen screen;

	if (!screen.init()) {
		std::cout << "Error initializing screen" << std::endl;
	}

	bool quit = false;

	while (!quit) {
		if(!screen.processEvents())
			quit = true;
	}

	screen.close();

	return 0;
}
