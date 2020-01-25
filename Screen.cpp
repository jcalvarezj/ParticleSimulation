/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#include "Screen.hpp"
#include <iostream>
#include <cstring>

namespace ParticleSimulation {

Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL),
	m_mainBuffer(NULL), m_backBuffer(NULL) {}

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

	m_mainBuffer = new Uint32[S_WIDTH * S_HEIGHT];
	m_backBuffer = new Uint32[S_WIDTH * S_HEIGHT];

	clear();
	memset(m_backBuffer, 0, S_WIDTH * S_HEIGHT * sizeof(Uint32));

	return true;
}

bool Screen::processEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event))
		if (event.type == SDL_QUIT)
			return false;

	return true;
}

void Screen::update() {
	SDL_UpdateTexture(m_texture, NULL, m_mainBuffer, S_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

void Screen::boxBlur() {
	Uint32 * aux = m_mainBuffer;
	m_mainBuffer = m_backBuffer;
	m_backBuffer = aux;

	for (int i = 0; i < S_HEIGHT; i++) {
		for (int j = 0; j < S_WIDTH; j++) {
			int redTotal = 0;
			int greenTotal = 0;
			int blueTotal = 0;

			for (int k = -1; k <= 1; k++) {
				for (int l = -1; l <= 1; l++) {
					int m = i + k;
					int n = j + l;

					if (m >= 0 && m < S_HEIGHT && n >= 0 && n < S_WIDTH) {
						Uint32 color = m_backBuffer[m * S_WIDTH + n];
						Uint8 red = color >> 24;
						Uint8 green = color >> 16;
						Uint8 blue = color >> 8;

						redTotal += red;
						greenTotal += green;
						blueTotal += blue;
					}
				}
			}

			Uint8 newRed = redTotal/9;
			Uint8 newGreen = greenTotal/9;
			Uint8 newBlue = blueTotal/9;

			setPixel(j, i, newRed, newGreen, newBlue);
		}
	}
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
	if (x >= 0 && x < S_WIDTH && y >= 0 && y < S_HEIGHT) {
		Uint32 color = 0;
		color += red;
		color <<= 8;
		color += green;
		color <<= 8;
		color += blue;
		color <<= 8;
		color += 0xFF;
		m_mainBuffer[y * S_WIDTH + x] = color;
	}
}

void Screen::clear() {
	memset(m_mainBuffer, 0, S_WIDTH * S_HEIGHT * sizeof(Uint32));
}

void Screen::close() {
	delete [] m_mainBuffer;
	delete [] m_backBuffer;

	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

} // namespace ParticleSimulation
