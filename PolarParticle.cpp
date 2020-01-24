/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "PolarParticle.hpp"
#include "Screen.hpp"

namespace ParticleSimulation {

PolarParticle::PolarParticle(int mode): m_phase(0), m_mode(mode), Particle(0, 0, 0, 0) {
	m_coord1 = 3.0 * rand() / RAND_MAX;
	m_coord2 = 2 * M_PI * rand() / RAND_MAX;

	switch (m_mode) {
		case Mode::POLR_FLWR:
			m_coord1Speed = -0.0015;
			m_coord2Speed = 0.0001;
			break;
		case Mode::POLR_SPRL:
			m_coord1Speed = -0.015;
			m_coord2Speed = 0.01;
			break;
		default:
			std::cout << "Polar mode not implemented!" << std::endl;
			break;
	}
}

void PolarParticle::update(int interval) {
	m_phase += m_coord1Speed * interval;
	m_coord2 += m_coord2Speed * interval;

	switch (m_mode) {
		case Mode::POLR_FLWR:
			m_coord1 = 300 * sin(4 * m_coord2 + m_phase);
			break;
		case Mode::POLR_SPRL:
			m_coord1 = (4 * m_coord2 + m_phase);
			break;
		default:
			std::cout << "Polar mode not implemented!" << std::endl;
	}
}

} // namespace ParticleSimulation
