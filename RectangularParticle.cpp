/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#include <stdlib.h>
#include <iostream>
#include "RectangularParticle.hpp"
#include "Screen.hpp"

namespace ParticleSimulation {

RectangularParticle::RectangularParticle(): m_x(0), m_y(0) {
	m_xSpeed = 0.005 * ((2.0 * rand() / RAND_MAX) - 1);
	m_ySpeed = 0.005 * ((2.0 * rand() / RAND_MAX) - 1);
}

void RectangularParticle::update() {
	if (m_x + m_xSpeed < -1 || m_x + m_xSpeed > 1)
		m_xSpeed *= -1;
	if (m_y + m_ySpeed < -1 || m_y + m_ySpeed > 1)
		m_ySpeed *= -1;

	m_x += m_xSpeed;
	m_y += m_ySpeed;
}

double RectangularParticle::getFirstCoordinate() {
	return m_x;
}

double RectangularParticle::getSecondCoordinate() {
	return m_y;
}

void RectangularParticle::toString() {
	std::cout << "P: " << m_x << ", " << m_y << std::endl;
}

} // namespace ParticleSimulation
