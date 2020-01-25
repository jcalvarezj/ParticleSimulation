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

/**
 * This Structure represents a Particle based on polar coordinates
 */
struct PolarParticle: Particle {
	double m_phase;

	/**
	 * Creates a PolarParticle instance with the specified mode
	 */
	PolarParticle(int mode);

	/**
	 * @see Particle#update
	 */
	void update(int interval);
};

} // namespace ParticleSimulation

#endif // POLAR_PARTICLE_HPP
