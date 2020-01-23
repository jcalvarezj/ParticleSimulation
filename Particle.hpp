/*
 * Header file definition
 *
 * @author J. Alvarez
 */

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

namespace ParticleSimulation {

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

