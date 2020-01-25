/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#include <stdlib.h>
#include <iostream>
#include "RectangularParticle.hpp"
#include "Screen.hpp"
#include <math.h>

namespace ParticleSimulation {

RectangularParticle::RectangularParticle(int mode): m_radSpeed(0),
	m_angle(0), Particle(0, 0, 0, 0, mode) {
		init();
}

void RectangularParticle::init() {
	m_coord1 = 0;
	m_coord2 = 0;
	switch (m_mode) {
		case Mode::RECT_RECT:
			m_coord1Speed = 0.0005 * ((2.0 * rand() / RAND_MAX) - 1);
			m_coord2Speed = 0.0005 * ((2.0 * rand() / RAND_MAX) - 1);
			break;
		case Mode::RECT_CIRC:
			m_angle = 2 * M_PI * rand() / RAND_MAX;
			m_radSpeed = 0.001 * rand() / RAND_MAX;
			break;
		case Mode::RECT_IMPD:
			m_angle = 2 * M_PI * rand() / RAND_MAX;
			m_radSpeed = 0.05 * rand() / RAND_MAX;
			m_radSpeed *= m_radSpeed;
			break;
		default:
			std::cout << "Rectangular mode not implemented!" << std::endl;
			break;
	}
}

void RectangularParticle::update(int interval) {
	switch(m_mode) {
		case Mode::RECT_CIRC:
			m_coord1Speed = m_radSpeed * cos(m_angle);
			m_coord2Speed = m_radSpeed * sin(m_angle);
			break;
		case Mode::RECT_RECT:
			if (m_coord1 + m_coord1Speed < -1 || m_coord1 + m_coord1Speed > 1)
				m_coord1Speed *= -1;
			if (m_coord2 + m_coord2Speed < -1 || m_coord2 + m_coord2Speed > 1)
				m_coord2Speed *= -1;
			break;
		case Mode::RECT_IMPD:
			m_angle += interval * 0.0003;
			m_coord1Speed = m_radSpeed * cos(m_angle);
			m_coord2Speed = m_radSpeed * sin(m_angle);

			if (m_coord1 < -1 || m_coord1 > 1 || m_coord2 < -1 || m_coord2 > 1)
				init();
			break;
	}

	m_coord1 += m_coord1Speed * interval;
	m_coord2 += m_coord2Speed * interval;
}

} // namespace ParticleSimulation
