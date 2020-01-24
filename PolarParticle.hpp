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
	PolarParticle();
	void update();
};

} // namespace ParticleSimulation

#endif // POLAR_PARTICLE_HPP
