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
	double m_x;
	double m_y;
	double m_xSpeed;
	double m_ySpeed;
	RectangularParticle();
	void update();
	double getFirstCoordinate();
	double getSecondCoordinate();
	void toString();
};

} // namespace ParticleSimulation

#endif // RECTANGULAR_PARTICLE_HPP
