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
	const static int N_PARTICLES = 4222;
	enum TYPE {RECT, POLAR};
private:
	Particle * * m_particles;
	int m_type;
	int m_lastUpdate;
public:
	/**
	 * Creates a Swarm instance based on a specified type and Particles mode
	 * @param type The Swarm type
	 * @param mode The Particles type
	 */
	Swarm(int type, int rectMode);

	/**
	 * Destructor method that ensures to delete the Swarm's Particles structure
	 */
	~Swarm();

	/**
	 * @return The Particles structure
	 */
	Particle * * getParticles();

	/**
	 * Updates all the Swarm's Particles
	 * @param elapsed Time of Screen rendering
	 */
	void update(int elapsed);

};

} // namespace ParticleSimulation

#endif // SWARM_HPP
