/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#ifndef SWARM_HPP
#define SWARM_HPP

#include "Particle.hpp"

namespace ParticleSimulation {

class Swarm {
public:
	const static int N_PARTICLES = 5000;
private:
	Particle * m_particles;
public:
	Swarm();
	~Swarm();
	Particle * getParticles();
};

} // namespace ParticleSimulation

#endif // SWARM_HPP
