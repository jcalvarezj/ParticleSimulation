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
	}

	Swarm swarm;

	bool quit = false;

	while (!quit) {

		const Particle * const particles = swarm.getParticles();

		for(int i = 0; i < Swarm::N_PARTICLES; i++) {
			Particle particle = particles[i];

			int x = (particle.m_x + 1) * Screen::S_WIDTH / 2;
			int y = (particle.m_y + 1) * Screen::S_HEIGHT / 2;

			screen.setPixel(x, y, 255, 255, 255);
		}

		/*
		int ellapsed = SDL_GetTicks();

		Uint8 green = (1 + sin(ellapsed * 0.001)) * 128;

		std::cout << "Now: " << (int)green << std::endl;

		for (int i = 0; i < Screen::S_HEIGHT; i++)
			for (int j = 0; j < Screen::S_WIDTH; j++)
				screen.setPixel(j, i, 0, green, 0);*/

		screen.update();

		if(!screen.processEvents())
			quit = true;
	}

	screen.close();

	return 0;
}
