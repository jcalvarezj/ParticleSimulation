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
	const static int N_PARTICLES = 1234;
	enum TYPE {RECT, POLAR};
private:
	Particle * * m_particles;
	int m_type;
public:
	Swarm(int type);
	~Swarm();
	Particle * * getParticles();
	void update();
	int getType();
};

} // namespace ParticleSimulation

#endif // SWARM_HPP
