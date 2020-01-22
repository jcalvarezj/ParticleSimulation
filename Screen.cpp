/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#include "Screen.h"
#include <iostream>

namespace ParticleSimulation {

Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL),
	m_buffer(NULL) {}

bool Screen::init() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Could not initialize SDL graphics" << std::endl;
		return false;
	}

	m_window = SDL_CreateWindow("Particle Simulation Program",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, S_WIDTH, S_HEIGHT, 
		SDL_WINDOW_SHOWN);

	if (!m_window) {
		std::cout << "Could not create the window. " << SDL_GetError() <<
			std::endl;
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1,
		SDL_RENDERER_PRESENTVSYNC);

	if (!m_renderer) {
		std::cout << "Could not create the renderer. " << SDL_GetError() << 
			std::endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STATIC, S_WIDTH, S_HEIGHT);

	if (!m_texture) {
		std::cout << "Could not create the texture. " << SDL_GetError() <<
		   std::endl;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_buffer = new Uint32[S_WIDTH * S_HEIGHT];

	memset(m_buffer, 0, S_WIDTH * S_HEIGHT * sizeof(Uint32));

	cint paintCol = S_WIDTH/2;
	cint paintRow = S_HEIGHT/2;

	for (int i = 0; i < S_HEIGHT; i++)
		m_buffer[i * S_WIDTH + paintCol] = 0x0FFFF0FF;

	for (int i = 0; i < S_WIDTH; i++)
		m_buffer[paintRow * S_WIDTH + i] = 0x0FFFF0FF;

	for (int i = 0; i < S_HEIGHT/2 - 1; i++)
		for (int j = 0; j < S_WIDTH/2 - 1; j++) {
			m_buffer[i * S_WIDTH + j] = 0xFFCC00FF;
			m_buffer[(i * S_WIDTH + j) + S_WIDTH/2 + 2] = 0x00CCF0FF;
			m_buffer[(i + S_HEIGHT/2 + 1) * S_WIDTH + j] = 0x0FCC0A00;
			m_buffer[(i + S_HEIGHT/2 + 1) * S_WIDTH + j + S_WIDTH/2 + 2] = 0xAD0C0A00;
		}

	m_buffer[40 * S_WIDTH + 100] = 0xFF00FF;
	m_buffer[40 * S_WIDTH + 101] = 0xFF00FF;
	m_buffer[40 * S_WIDTH + 102] = 0xFF00FF;
	m_buffer[40 * S_WIDTH + 103] = 0xFF0000;
	m_buffer[40 * S_WIDTH + 104] = 0xFF0000;

	SDL_UpdateTexture(m_texture, NULL, m_buffer, S_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);

	return true;
}

bool Screen::processEvents() {
	return true;
}

void Screen::close() {
	delete [] m_buffer;

	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

} // namespace ParticleSimulation
