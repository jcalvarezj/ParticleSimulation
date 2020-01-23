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

RectangularParticle::RectangularParticle(): Particle(0,0) {
	m_coord1Speed = 0.005 * ((2.0 * rand() / RAND_MAX) - 1);
	m_coord2Speed = 0.005 * ((2.0 * rand() / RAND_MAX) - 1);
}

void RectangularParticle::update() {
	if (m_coord1 + m_coord1Speed < -1 || m_coord1 + m_coord1Speed > 1)
		m_coord1Speed *= -1;
	if (m_coord2 + m_coord2Speed < -1 || m_coord2 + m_coord2Speed > 1)
		m_coord2Speed *= -1;

	m_coord1 += m_coord1Speed;
	m_coord2 += m_coord2Speed;
}

} // namespace ParticleSimulation
