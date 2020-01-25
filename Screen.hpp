/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#include "SDL2/SDL.h"

#ifndef SCREEN_HPP
#define SCREEN_HPP

typedef const unsigned int cint;

namespace ParticleSimulation {

/**
 * This class represents the graphic interface where the particles are shown
 */
class Screen {
public:
	const static unsigned int S_WIDTH = 800;
	const static unsigned int S_HEIGHT = 600;
private:
	SDL_Window * m_window;
	SDL_Renderer * m_renderer;
	SDL_Texture * m_texture;
	Uint32 * m_mainBuffer;
	Uint32 * m_backBuffer;
public:
	/**
	 * Creates a Screen instance and initializes it fields
	 */
	Screen();

	/**
	 * Initializes window, renderer, texture, and buffer
	 * @return boolean indicating success of the initialization process
	 */
	bool init();

	/**
	 * Unstacks events from the event pool and processes them
	 * @return boolean indicating whether the program should continue or not
	 */
	bool processEvents();

	/**
	 * Updates the Screen's elements according to the information in the buffer
	 */
	void update();

	/**
	 * Applies a box blur to the previous state of the Screen
	 */
	void boxBlur();

	/**
	 * Sets a pixel in the buffer with the specified (x,y) position, and colors
	 * @param x The x position
	 * @param y The y position
	 * @param red The value of the red color component
	 * @param green The value of the green color component
	 * @param blue The value of the blue color component
	 */
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);

	/**
	 * Clears the Screen's main buffer (set it to all zeros)
	 */
	void clear();

	/**
	 * Closes the Screen and cleans memory from all its elements
	 */
	void close();
};

} // namespace ParticleSimulation

#endif // SCREEN_HPP

