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
#include "RectangularParticle.hpp"

using namespace ParticleSimulation;

int main(int argc, char ** args) {	
	srand(time(NULL));

	Screen screen;

	if (!screen.init()) {
		std::cout << "Error initializing screen" << std::endl;
		return -1;
	}

	int swarmType = 0;
	int mode = 0;

	switch (argc) {
		case 1:
			swarmType = Swarm::TYPE::POLAR;
			mode = Particle::Mode::POLR_FLWR;
			break;
		case 2:
			swarmType = Swarm::TYPE::POLAR;
			mode = Particle::Mode::POLR_SPRL;
			break;
		case 3:
			swarmType = Swarm::TYPE::RECT;
			mode = Particle::Mode::RECT_RECT;
			break;
		default:
			swarmType = Swarm::TYPE::RECT;
			mode = Particle::Mode::RECT_CIRC;
			break;
	}

	Swarm swarm(swarmType, mode);

	bool quit = false;

	while (!quit) {
		int elapsed = SDL_GetTicks();

		Uint8 red = (1 + sin(elapsed * 0.001)) * 128;
		Uint8 green = (1 + sin(elapsed * 0.0002)) * 128;
		Uint8 blue = (1 + sin(elapsed * 0.0003)) * 128;

		swarm.update(elapsed);
		Particle * * particles = swarm.getParticles();

		screen.clear();

		for (int i = 0; i < Swarm::N_PARTICLES; i++) {
			Particle * particle = particles[i];

			double coord1 = particle->m_coord1;
			double coord2 = particle->m_coord2;

			int x = 0;
			int y = 0;

			if (swarmType == Swarm::TYPE::RECT) {
				if (mode == Particle::Mode::RECT_RECT)
					x = (coord1 + 1) * Screen::S_WIDTH / 2;
				else
					x = coord1 * Screen::S_HEIGHT / 2 + Screen::S_WIDTH / 2;
				y = (coord2 + 1) * Screen::S_HEIGHT / 2;
			}
			else {
				x = (coord1 * cos(coord2)) + Screen::S_WIDTH / 2;
				y = (coord1 * sin(coord2)) + Screen::S_HEIGHT / 2;
			}

			screen.setPixel(x, y, red, green, blue);
		}

		screen.update();

		if(!screen.processEvents())
			quit = true;
	}

	screen.close();

	return 0;
}
