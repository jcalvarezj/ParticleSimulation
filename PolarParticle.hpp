/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#ifndef POLAR_PARTICLE_HPP
#define POLAR_PARTICLE_HPP

#include "Particle.hpp"

namespace ParticleSimulation {

struct PolarParticle: Particle {
	int m_mode;
	double m_phase;
	PolarParticle(int mode);
	void update(int interval);
};

} // namespace ParticleSimulation

#endif // POLAR_PARTICLE_HPP
