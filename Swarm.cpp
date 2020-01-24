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

Swarm::Swarm(int type, int rectMode): m_type(type) {
	switch (m_type) {
		case TYPE::RECT:
			m_particles = new Particle * [N_PARTICLES];
			for (int i = 0; i < N_PARTICLES; i++)
				m_particles[i] = new RectangularParticle(rectMode);
			break;
		case TYPE::POLAR:
			m_particles = new Particle * [N_PARTICLES];
			for (int i = 0; i < N_PARTICLES; i++)
				m_particles[i] = new PolarParticle;
			break;
		default:
			std::cout << "Type not implemented!!!" << std::endl;
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

void Swarm::update() {
	for (int i = 0; i < N_PARTICLES; i++)
		m_particles[i]->update();
}

int Swarm::getType() {
	return m_type;
}

} // namespace ParticleSimulation
