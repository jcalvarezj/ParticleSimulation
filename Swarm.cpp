/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#include <iostream>
#include "Swarm.hpp"
#include "Particle.hpp"
#include "RectangularParticle.hpp"
#include "PolarParticle.hpp"

namespace ParticleSimulation {

Swarm::Swarm(int type, int mode): m_type(type), m_lastUpdate(0) {
	switch (m_type) {
		case TYPE::RECT:
			m_particles = new Particle * [N_PARTICLES];
			for (int i = 0; i < N_PARTICLES; i++)
				m_particles[i] = new RectangularParticle(mode);
			break;
		case TYPE::POLAR:
			m_particles = new Particle * [N_PARTICLES];
			for (int i = 0; i < N_PARTICLES; i++)
				m_particles[i] = new PolarParticle(mode);
			break;
		default:
			std::cout << "Swarm type not implemented!!!" << std::endl;
			break;
	}
}

Swarm::~Swarm() {
	for (int i = 0; i < N_PARTICLES; i++)
		delete m_particles[i];
	delete [] m_particles;
}

Particle * * Swarm::getParticles() {
	return m_particles;
}

void Swarm::update(int elapsed) {
	for (int i = 0; i < N_PARTICLES; i++)
		m_particles[i]->update(elapsed - m_lastUpdate);
	m_lastUpdate = elapsed;
}


} // namespace ParticleSimulation
