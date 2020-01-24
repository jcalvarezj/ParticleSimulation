/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#ifndef PARTICLE_HPP
#define PARTICLE_HPP

namespace ParticleSimulation {

/**
 * This Struct represents Particles in general: particles with rectangular or
 * polar coordinates. For rectangular coordinates, coord1 and 2 are x and y
 * respectively; for polar coodinates, r and theta.
 */
struct Particle {
	double m_coord1;
	double m_coord2;
	double m_coord1Speed;
	double m_coord2Speed;

	Particle(int coord1, int coord2): m_coord1(coord1), m_coord2(coord2) {}

	virtual void update() = 0;
};

} // namespace ParticleSimulation

#endif // PARTICLE_HPP

