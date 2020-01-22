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

		int ellapsed = SDL_GetTicks();

		Uint8 red = (1 + sin(ellapsed * 0.001)) * 128;
		Uint8 green = (1 + sin(ellapsed * 0.002)) * 128;
		Uint8 blue = (1 + sin(ellapsed * 0.003)) * 128;

		for(int i = 0; i < Swarm::N_PARTICLES; i++) {
			Particle particle = particles[i];

			int x = (particle.m_x + 1) * Screen::S_WIDTH / 2;
			int y = (particle.m_y + 1) * Screen::S_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.update();

		if(!screen.processEvents())
			quit = true;
	}

	screen.close();

	return 0;
}
