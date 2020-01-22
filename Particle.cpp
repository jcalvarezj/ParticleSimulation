/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#include <stdlib.h>
#include "Particle.hpp"

namespace ParticleSimulation {

Particle::Particle() {
	m_x = (2.0 * rand() / RAND_MAX) - 1;
	m_y = (2.0 * rand() / RAND_MAX) - 1;
}

} // namespace ParticleSimulation
