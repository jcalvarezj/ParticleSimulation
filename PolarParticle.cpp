/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#include <stdlib.h>
#include <math.h>
#include "PolarParticle.hpp"
#include "Screen.hpp"

namespace ParticleSimulation {

PolarParticle::PolarParticle(): m_phase(0), Particle(0, 0, 0, 0) {
	m_coord1 = 3.0 * rand() / RAND_MAX;
	m_coord2 = 2 * M_PI * rand() / RAND_MAX;
	m_coord1Speed = -0.2;
	m_coord2Speed = 0.1;
}

void PolarParticle::update() {
	m_phase += m_coord1Speed;
	m_coord2 += m_coord2Speed;
	m_coord1 = 300 * sin(4 * m_coord2 + m_phase);
}

} // namespace ParticleSimulation
