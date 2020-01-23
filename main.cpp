/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Screen.hpp"
#include "Swarm.hpp"
#include "SDL2/SDL.h"

using namespace ParticleSimulation;

int main(int argc, char ** args) {
	srand(time(NULL));

	Screen screen;

	if (!screen.init()) {
		std::cout << "Error initializing screen" << std::endl;
		return -1;
	}

	Swarm swarm(Swarm::TYPE::RECT);

	bool quit = false;

	while (!quit) {
		swarm.update();

		Particle * * particles = swarm.getParticles();

		int ellapsed = SDL_GetTicks();

		Uint8 red = (1 + sin(ellapsed * 0.001)) * 128;
		Uint8 green = (1 + sin(ellapsed * 0.0002)) * 128;
		Uint8 blue = (1 + sin(ellapsed * 0.0003)) * 128;

		screen.clear();

		for (int i = 0; i < Swarm::N_PARTICLES; i++) {
			Particle * particle = particles[i];

			double coord1 = particle->getFirstCoordinate();
			double coord2 = particle->getSecondCoordinate();

			int x = (coord1 + 1) * Screen::S_WIDTH / 2;
			int y = (coord2 + 1) * Screen::S_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.update();

		if(!screen.processEvents())
			quit = true;
	}

	screen.close();

	return 0;
}
