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
	RectangularParticle();
	void update();
};

} // namespace ParticleSimulation

#endif // RECTANGULAR_PARTICLE_HPP
