/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#include <iostream>
#include "Swarm.hpp"
#include "Particle.hpp"

namespace ParticleSimulation {

Swarm::Swarm() {
	m_particles = new Particle[N_PARTICLES];
}

Swarm::~Swarm() {
	delete [] m_particles;
}

Particle * Swarm::getParticles() {
	return m_particles;
}

} // namespace ParticleSimulation
