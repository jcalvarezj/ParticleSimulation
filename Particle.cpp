/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#include <stdlib.h>
#include "Particle.hpp"
#include "Screen.hpp"

namespace ParticleSimulation {

Particle::Particle() {
	m_x = (2.0 * rand() / RAND_MAX) - 1;
	m_y = (2.0 * rand() / RAND_MAX) - 1;
	m_xSpeed = 0.01 * ((2.0 * rand() / RAND_MAX) - 1);
	m_ySpeed = 0.01 * ((2.0 * rand() / RAND_MAX) - 1);
}

void Particle::update() {
	if (m_x + m_xSpeed < -1 || m_x + m_xSpeed > 1)
		m_xSpeed *= -1;
	if (m_y + m_ySpeed < -1 || m_y + m_ySpeed > 1)
		m_ySpeed *= -1;

	m_x += m_xSpeed;
	m_y += m_ySpeed;
}

} // namespace ParticleSimulation
