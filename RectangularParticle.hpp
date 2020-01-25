/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#ifndef RECTANGULAR_PARTICLE_HPP
#define RECTANGULAR_PARTICLE_HPP

#include "Particle.hpp"

namespace ParticleSimulation {

struct RectangularParticle: Particle {
	double m_radSpeed;
	double m_angle;

	/**
	 * Creates an instance of RectangularParticle with a specified mode
	 */
	RectangularParticle(int mode);

	/**
	 * Initializes the RectangularParticle's fields
	 */
	void init();

	/**
	 * @see Particle#update
	 */
	void update(int interval);
};

} // namespace ParticleSimulation

#endif // RECTANGULAR_PARTICLE_HPP
