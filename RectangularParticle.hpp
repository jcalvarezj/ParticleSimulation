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
	int m_mode;
	double m_radSpeed;
	double m_angle;

	RectangularParticle(int mode);
	void init();
	void update(int interval);
};

} // namespace ParticleSimulation

#endif // RECTANGULAR_PARTICLE_HPP
