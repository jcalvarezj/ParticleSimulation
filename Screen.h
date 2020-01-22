/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#include "SDL2/SDL.h"

#ifndef SCREEN_H
#define SCREEN_H

typedef const unsigned int cint;

namespace ParticleSimulation {
class Screen {
public:
	const static unsigned int S_WIDTH = 800;
	const static unsigned int S_HEIGHT = 600;
private:
	SDL_Window * m_window;
	SDL_Renderer * m_renderer;
	SDL_Texture * m_texture;
	Uint32 * m_buffer;
public:
	Screen();
	bool init();
	bool processEvents();
	void close();
};
} // namespace ParticleSimulation

#endif // SCREEN_H

